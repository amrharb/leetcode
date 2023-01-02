class Solution {
public:
    bool detectCapitalUse(string word) {
        int lower=0,upper=0;
        int n=word.size();
        for(auto&it:word){
            lower+=(bool)islower(it);
            upper+=(bool)isupper(it);
        }
        return (lower==n||upper==n||isupper(word[0])&&upper==1);
    }
};