class Solution {
public:
    bool isPalindrome(string str){
        string rev=str;
        reverse(rev.begin(),rev.end());
        return rev==str;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=s[n-i-1]){
                int j=n-i-1;
                string rem_after_del_j=s.substr(i,j-i);
                string rem_after_del_i=s.substr(i+1,j-i);
                if(isPalindrome(rem_after_del_j)||isPalindrome(rem_after_del_i))
                    return true;
                else
                    return false;
            }
        }
        return true;
    }
};