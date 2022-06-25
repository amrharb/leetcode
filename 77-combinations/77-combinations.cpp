class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        for(int i=1;i<(1<<n);i++){
            vector<int>v;
            for(int j=1;j<=n;j++){
                if(i&(1<<(j-1)))v.push_back(j);
            }
            if(v.size()==k)ans.push_back(v);
        }
        return ans;
    }
};