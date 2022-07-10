class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>v(n+5,0);
        v[1]=cost[0];
        for(int i=2;i<=n;i++)v[i]=cost[i-1]+min(v[i-1],v[i-2]);
        return min(v[n],v[n-1]);
    }
};