class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int>time(n);
        for(int i=0;i<n;i++){
            time[i]=(dist[i]+speed[i]-1)/speed[i];
        }
        sort(time.begin(),time.end());
        int ans=1;
        for(int i=1;i<n;i++){
            if(time[i]<=ans)
                return ans;
            ans++;
        }
        return ans;
    }
};