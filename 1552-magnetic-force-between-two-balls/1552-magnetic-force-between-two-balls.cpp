class Solution {
public:
    bool check(int k,vector<int>v,int cnt){
        int n=v.size();
        for(int i=0;i<n&&cnt;){
            cnt--;
            i=lower_bound(v.begin()+i,v.end(),v[i]+k)-v.begin();
        }
        return !cnt;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l=0,r=1e9;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid,position,m))l=mid+1;
            else r=mid-1;
        }
        return l-1;
    }
};