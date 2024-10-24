class Solution {
public:
    bool isPalindrome(string s){
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size(),i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                string rem_after_del_j=s.substr(i,j-i);
                string rem_after_del_i=s.substr(i+1,j-i);
                if(isPalindrome(rem_after_del_j)||isPalindrome(rem_after_del_i))
                    return true;
                else
                    return false;
            }
            i++,j--;
        }
        return true;
    }
};