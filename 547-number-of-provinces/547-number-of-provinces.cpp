class Solution {
public:
    struct DSU{
        int numgroups;
        vector<int>p,sz;
        void init(int n){
            numgroups=n;
            p=vector<int>(n,0);
            sz=vector<int>(n,1);
            for(int i=0;i<n;i++)p[i]=i;
        }
        int get(int a){
            return p[a]=(p[a]==a ? a:get(p[a]));
        }
        void join(int a,int b){
            a=get(a);
            b=get(b);
            if(a==b)return;
            if(sz[a]>sz[b])swap(a,b);
            p[a]=b;
            sz[b]+=sz[a];
            numgroups--;
        }
    }dsu;
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        dsu.init(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j])dsu.join(i,j);
            }
        }
        return dsu.numgroups;
    }
};