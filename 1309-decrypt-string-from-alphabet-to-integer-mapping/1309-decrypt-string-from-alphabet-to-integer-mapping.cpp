class Solution {
public:
    string freqAlphabets(string s) {
        int n=s.size();
        string x;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='#'){
                x+=char((s[i-2]-'0')*10+(s[i-1]-'1')+'a');
                i-=2;
            }
            else{
                x+=char(s[i]-'1'+'a');
            }
        }
        reverse(x.begin(),x.end());
        return x;
    }
};