class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        vector<int>pref,suf;
        pref=suf=card;
        suf.push_back(0);
        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1];
        }
        for(int i=n-2;i>=0;i--)suf[i]+=suf[i+1];
        int mx=suf[n-k];
        for(int i=0;i<k;i++){
            mx=max(mx,pref[i]+suf[n-(k-i-1)]);
        }
        return mx;
    }
};