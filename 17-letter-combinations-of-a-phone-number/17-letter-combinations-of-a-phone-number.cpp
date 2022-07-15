class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int,string>mp;
        mp[2]="abc",mp[3]="def",mp[4]="ghi",mp[5]="jkl",mp[6]="mno",mp[7]="pqrs",mp[8]="tuv",mp[9]="wxyz";
        map<string,int>mk;
        mk[""]=1;
        vector<string>last;
        for(auto&it:digits){
            vector<string>v;
            for(auto&el:mp[it-'0']){
                for(auto&k:mk){
                    v.push_back(k.first+el);
                }
            }
            mk.clear();
            for(auto&it:v)mk[it]=1;
            last=v;
        }
        return last;;
    }
};