class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        hor.push_back(0);
        hor.push_back(h);
        ver.push_back(0);
        ver.push_back(w);
        int n=hor.size(),m=ver.size(),mod=1e9+7,mxH=0,mxV=0;
        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());
        for(int i=1;i<n;i++){
           mxH=max(mxH,hor[i]-hor[i-1]);
        }
        for(int i=1;i<m;i++){
            mxV=max(mxV,ver[i]-ver[i-1]);
        }
        return mxH*1LL*mxV%mod;
    }
};