class Solution {
public:
    int n;
    vector<int>v;
    bool check(int k){
        int cnt=n;
        for(int i=0;i<v.size()&&cnt;){
            cnt--;
            i=lower_bound(v.begin()+i,v.end(),v[i]+k)-v.begin();
        }
        return !cnt;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        n=m,v=position;
        int l=0,r=1e9;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid))l=mid+1;
            else r=mid-1;
        }
        return l-1;
    }
};