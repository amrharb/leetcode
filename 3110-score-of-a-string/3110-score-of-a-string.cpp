class Solution {
public:
    int scoreOfString(string s) {
        int sum=0,n=s.size();
        for(int i=1;i<n;i++)
        {
            sum+=abs(s[i]-s[i-1]);
        }
        return sum;
    }
};