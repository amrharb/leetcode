class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans=0,n=s.size();
        for(int i=0;i<n;i++){
            ans+=mp[s[i]];
            if(i){
                if((s[i]=='V'||s[i]=='X')&&s[i-1]=='I')ans-=2;
                if((s[i]=='L'||s[i]=='C')&&s[i-1]=='X')ans-=20;
                if((s[i]=='D'||s[i]=='M')&&s[i-1]=='C')ans-=200;
            }
        }
        return ans;
    }   
};