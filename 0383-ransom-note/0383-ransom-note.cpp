class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>freq(26);
        for(auto it:magazine)
            freq[it-'a']++;
        for(auto it:ransomNote){
            if(!freq[it-'a'])
                return false;
            freq[it-'a']--;
        }
        return true;
    }
};