class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>freq;
        for(auto&it:arr)
        {
            freq[it]++;
        }
        int cnt=freq.size();
        map<int,int>mp;
        for(auto&[a,b]:freq)
            mp[b]++;
        for(auto&[a,b]:mp)
        {
            while(b--&&k>=a)
                k-=a,cnt--;
        }
        return cnt;
    }
};