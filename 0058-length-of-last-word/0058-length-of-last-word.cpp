class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        while(iss>>s);
        return s.size();
    }
};