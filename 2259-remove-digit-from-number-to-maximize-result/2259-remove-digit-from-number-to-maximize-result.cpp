class Solution {
public:
    string removeDigit(string num, char digit) {
        int n=num.size(),last=-1;
        for(int i=0;i<n;i++){
            if(num[i]==digit&&i+1<n&&num[i]<num[i+1]){
                num.erase(i,1);
                return num;
            }
            if(num[i]==digit)last=i;
        }
        num.erase(last,1);
        return num;
    }
};