class Solution {
public:
    int ans[1005];
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        ans[0]=cost[0],ans[1]=cost[1];
        for(int i=2;i<n;i++){
            ans[i]=min(ans[i-1],ans[i-2])+cost[i];
        }
        return min(ans[n-1],ans[n-2]);
    }
};