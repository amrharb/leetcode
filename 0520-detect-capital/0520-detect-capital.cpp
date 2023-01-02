class Solution {
public:
    bool detectCapitalUse(string word) {
        int lower=0,upper=0;
        int n=word.size();
        for(auto&it:word){
            lower+=(it>='a'&&it<='z');
            upper+=(it>='A'&&it<='Z');
        }
        return (lower==n||upper==n||(word[0]>='A'&&word[0]<='Z')&&upper==1);
    }
};