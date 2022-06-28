class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        vector<long long>pref(n);
        pref[0]=chalk[0];
        for(int i=1;i<n;i++)pref[i]=chalk[i]+pref[i-1];
        k-=k/pref[n-1]*pref[n-1];
        return upper_bound(pref.begin(),pref.end(),k)-pref.begin();
    }
};