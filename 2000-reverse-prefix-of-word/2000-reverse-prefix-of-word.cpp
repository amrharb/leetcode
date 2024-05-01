class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size(),idx = word.find(ch);
        if(!~idx)
            return word;
        reverse(word.begin(),word.begin()+idx+1);
        return word;
    }
};