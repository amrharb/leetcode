class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) {
        int n=v.size(),mn=1e9;
        vector<int>pref=v;
        for(int i=1;i<n;i++)pref[i]+=pref[i-1];
        for(int i=0;i<n;i++){
            int k=lower_bound(pref.begin()+i,pref.end(),(!i ? 0:pref[i-1])+target)-pref.begin();
            if(k!=n)mn=min(mn,k-i+1);
        }
        if(mn>n)mn=0;
        return mn;
    }
};