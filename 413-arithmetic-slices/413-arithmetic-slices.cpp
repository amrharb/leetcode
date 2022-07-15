class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        int n=v.size();
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            for(int j=i+2;j<n;j++){
                if(v[j]-v[j-1]==v[i+1]-v[i])dp[j]++;
                else break;
            }
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};