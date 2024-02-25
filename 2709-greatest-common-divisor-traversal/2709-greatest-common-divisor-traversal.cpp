const int N=1e5+5;
class Solution {
public:
    int adj[N];
    struct DSU
    {
        int p[N],sz[N],cnt;
        void init(int n)
        {
            cnt=n;
            iota(p,p+n,0);
            fill(sz,sz+n,1);
        }
        int get(int a)
        {
            return p[a]=(p[a]==a ? a:get(p[a]));
        }
        bool join(int a,int b)
        {
            a=get(a),b=get(b);
            if(a==b)return 0;
            if(sz[a]>sz[b])swap(a,b);
            p[a]=b;
            sz[b]+=sz[a];
            cnt--;
            return 1;
        }
    } dsu;
    bool canTraverseAllPairs(vector<int>& nums) {
        memset(adj,-1,sizeof adj);
        int n=nums.size();
        dsu.init(n);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j*j<=nums[i];j++)
            {
                if(nums[i]%j==0)
                {
                    if(j!=1)
                    {
                        if(~adj[j])
                            dsu.join(i,adj[j]);
                    }
                    if(nums[i]/j!=1)
                    {
                        if(~adj[nums[i]/j])
                            dsu.join(i,adj[nums[i]/j]);
                    }
                    adj[j]=adj[nums[i]/j]=i;
                }
            }
        }
        return dsu.cnt==1;
    }
};