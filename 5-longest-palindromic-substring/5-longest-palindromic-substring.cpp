class Solution {
public:
    string s;
    bool check(int i,int j){
        for(;i<j;i++,j--){
            if(s[i]!=s[j])return 0;
        }
        return 1;
    }
    string longestPalindrome(string x) {
        s=x;
        string ans;
        int mx=0,n=s.size();
       for(int i=0;i<n;i++){
           for(int j=n-1;j>=i;j--){
               if(j-i+1<=mx)continue;
               if(check(i,j)){
                   mx=j-i+1;
                   ans=s.substr(i,j-i+1);
               }
           }
       }
        return ans;
    }
};