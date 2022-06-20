class Solution {
public:
    bool checkInclusion(string s, string x) {
        int n=s.size(),m=x.size();
        string k;
        sort(s.begin(),s.end());
        for(int i=0;i<=m-n;i++){
            k=x.substr(i,n);
            sort(k.begin(),k.end());
            if(k==s)return 1;
        }
        return 0;
    }
};