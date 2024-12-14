class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size(),m=max(1,numRows*2-2);
        string ans;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<n;j+=m){
                if(i+j<n)
                   ans+=s[i+j];
                if(i&&i!=numRows-1&&j+m-i<n)
                   ans+=s[j+m-i];
            }
        }
        return ans;
    }
};