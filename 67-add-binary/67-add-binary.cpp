class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans;
        int l=0,r=0,n=a.size(),m=b.size();
        bool carry=0;
        while(l<n||r<m){
            if(l>=n){
                ans.push_back(b[r++]-'0'+carry);
                if(ans.back()<=1)carry=0;
                else carry=1;
                ans.back()=(ans.back()%2+'0');
            }
            else if(r>=m){
                ans.push_back(a[l++]-'0'+carry);
                if(ans.back()<=1)carry=0;
                else carry=1;
                ans.back()=(ans.back()%2+'0');
            }
            else{
                ans.push_back(a[l++]-'0'+b[r++]-'0'+carry);
                if(ans.back()<=1)carry=0;
                else carry=1;
                ans.back()=(ans.back()%2+'0');
            }
        }
        if(carry)ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};