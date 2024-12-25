class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        string ans=num;
        bool start=0;
        int n=num.size();
        for(int i=0;i<n;i++){
            if(num[i]-'0'>change[num[i]-'0']){
                if(start)
                    break;
            }else if(num[i]-'0'<change[num[i]-'0']){
                ans[i]=char(change[num[i]-'0']+'0');
                start=1;
            }
        }
        return ans;
    }
};