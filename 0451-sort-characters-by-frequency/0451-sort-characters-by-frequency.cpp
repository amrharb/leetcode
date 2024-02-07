class Solution {
public:
    string frequencySort(string s) {
        map<char,int>freq;
        for(auto&it:s)
            freq[it]++;
        map<int,vector<char>,greater<>>mp;
        for(auto&it:freq)
            mp[it.second].push_back(it.first);
        string ans;
        for(auto&[a,b]:mp)
        {
            for(auto&it:b)
                for(int i=1;i<=a;i++)
                    ans+=it;
        }
        return ans;
    }
};