class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(),s.rend());
        int last=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
                break;
            last=i;
        }
        s[last]='0';
        s[n-1]='1';
        return s;
    }
};