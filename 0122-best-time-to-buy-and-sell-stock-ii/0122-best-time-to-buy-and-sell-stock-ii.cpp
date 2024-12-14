class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0,mn=INT_MAX,n=prices.size();
        for(int i=0;i<n;i++){
            mn=min(mn,prices[i]);
            if(prices[i]>mn)
                sum+=prices[i]-mn,mn=prices[i];
        }
        return sum;
    }
};