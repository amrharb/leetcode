class Solution {
public:
    int lengthOfLastWord(string s) {
        int sz=0;
        istringstream iss(s);
        while(iss>>s)
            sz=s.size();
        return sz;
    }
};