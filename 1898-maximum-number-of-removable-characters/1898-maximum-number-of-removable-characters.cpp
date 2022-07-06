class Solution {
public:
    string a,b;
    vector<int>c;
    int n,m,x;
    bool check(int k){
        vector<bool>vis(n);
        for(int i=0;i<=k;i++){
            vis[c[i]]=1;
        }
        int j=0;
        for(int i=0;i<n&&j<x;i++){
            if(!vis[i]){
                if(a[i]==b[j])j++;
            }
        }
        return !(j==x);
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        a=s,b=p,c=removable;
        n=a.size(),m=c.size(),x=b.size();
        int l=0,r=m-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid))r=mid-1;
            else l=mid+1;
        }
        return r+1;
    }
};