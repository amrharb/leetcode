class Solution {
public:
    struct DSU{
        vector<int>p,sz;
        void init(int n){
            sz=vector<int>(n,1);
            p=vector<int>(n);
            for(int i=0;i<n;i++)p[i]=i;
        }
        int get(int a){
            return p[a]=(p[a]==a ? a:get(p[a]));
        }
        void join(int a,int b){
            a=get(a),b=get(b);
            if(a==b)return;
            if(sz[a]>sz[b])swap(a,b);
            p[a]=b;
            sz[b]+=sz[a];
        }
        bool ask(int a,int b){
            a=get(a),b=get(b);
            return a==b;
        }
    }dsu;
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        dsu.init(n);
        for(int i=0;i<n;i++){
            for(auto&it:adj[i]){
                for(auto&el:adj[it])dsu.join(i,el);
            }
        }
        for(int i=0;i<n;i++){
            for(auto&it:adj[i]){
                if(dsu.ask(i,it))return 0;
            }
        }
        return 1;
    }
};