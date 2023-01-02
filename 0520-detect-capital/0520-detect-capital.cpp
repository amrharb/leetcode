class Solution {
public:
    bool detectCapitalUse(string word) {
        int lower=0,upper=0;
        int n=word.size();
        for(int i=0;i<n;i++){
            lower+=(bool)islower(word[i]);
            upper+=(bool)isupper(word[i]);
        }
        return (lower==n||upper==n||isupper(word[0])&&upper==1);
    }
};