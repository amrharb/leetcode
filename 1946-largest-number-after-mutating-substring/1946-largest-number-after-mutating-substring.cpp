class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool start=0;
        for(char &d:num){
            if(d-'0'>change[d-'0']){
                if(start)
                    break;
            }else if(d-'0'<change[d-'0']){
                d=char(change[d-'0']+'0');
                start=1;
            }
        }
        return num;
    }
};