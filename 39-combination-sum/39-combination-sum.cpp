class Solution {
public:
    int n;
    vector<int>a;
    set<vector<int>>ans;
    void solve(int i,int rem,vector<int>v){
        if(i==n||!rem){
            if(!rem)ans.insert(v);
            return;
        }
        solve(i+1,rem,v);
        int k=1;
        while(rem>=k*a[i]){
            v.push_back(a[i]);
            solve(i+1,rem-k*a[i],v);
            k++;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        a=candidates;
        solve(0,target,{});
        vector<vector<int>>k(ans.begin(),ans.end());
        return k;
    }
};