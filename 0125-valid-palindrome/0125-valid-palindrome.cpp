class Solution {
public:
    bool isPalindrome(string s) {
        string nw_str;
        for(auto it:s){
            if(isalpha(it)||isdigit(it)){
                nw_str+=tolower(it);
            }
        }
        string reversed_str=nw_str;
        reverse(reversed_str.begin(),reversed_str.end());
        return nw_str==reversed_str;
    }
};