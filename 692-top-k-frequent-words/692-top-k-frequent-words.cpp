class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        map<int,vector<string>,greater<int>>mk;
        for(auto it:words)mp[it]++;
        for(auto&it:mp)mk[it.second].push_back(it.first);
        vector<string>ans;
        for(auto&it:mk){
            for(auto el:it.second){
                ans.push_back(el);
                if(!--k)break;
            }
            if(!k)break;
        }
        return ans;
    }
};