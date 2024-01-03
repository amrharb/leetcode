class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size(),org=0;
        for(auto&it:nums)
            org+=it;
        vector<vector<int>>adj(n);
        for(int i=0;i<(1<<n/2);i++)
        {
            bitset<15>bs(i);
            int sum=0;
            for(int j=0;j<n/2;j++)
            {
                if(i&(1<<j))
                {
                    sum+=nums[j];
                }
            }
            adj[bs.count()].push_back(sum);
        }
        for(auto&v:adj)
            sort(v.begin(),v.end());
        int mn=1e9;
        for(int i=0;i<(1<<(n/2));i++)
        {
            bitset<15>bs(i);
            int sum=0;
            for(int j=0;j<n/2;j++)
            {
                if(i&(1<<j))
                {
                    sum+=nums[n/2+j];
                }
            }
            auto it=lower_bound(adj[n/2-bs.count()].begin(),adj[n/2-bs.count()].end(),org/2-sum)-adj[n/2-bs.count()].begin();
            if(it!=adj[n/2-bs.count()].size())
            {
                int cur=adj[n/2-bs.count()][it]+sum;
                mn=min(mn,abs(cur-(org-cur)));
            }
            if(it!=0)
            {
                --it;
                int cur=adj[n/2-bs.count()][it]+sum;
                mn=min(mn,abs(cur-(org-cur))); 
            }
        }
        return mn;
    }
};