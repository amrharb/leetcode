class Solution {
public:
    int n;
    vector<int>v;
    bool check(int k){
        int cnt=n,last=0;
        for(int i=0;i<v.size()&&cnt;i++){
            if(v[i]>=last){
                cnt--;
                last=v[i]+k;
            }
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