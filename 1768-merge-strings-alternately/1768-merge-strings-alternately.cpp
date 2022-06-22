class Solution {
public:
    string mergeAlternately(string s, string x) {
        int n=s.size(),m=x.size();
        string nw;
        for(int i=0;i<n+m;i++){
            if(i&1){
                if(i/2<m)nw+=x[i/2];
                else{
                    nw+=s.substr((i+1)/2);
                    break;
                }
            }
            else{
                if(i/2<n)nw+=s[i/2];
                else{
                    nw+=x.substr(i/2);
                    break;
                }
            }
        }
        return nw;
    }
};