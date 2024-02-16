class Solution {
public:
    int maxIncreasingGroups(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        int cnt=1;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
            if(sum>=cnt*1LL*(cnt+1)/2)
                cnt++;
        }
        return cnt-1;
    }
};