class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(),cnt=0;
        for(int i=0;i<n;i++)
        {
            deque<char>forward,backward;
            for(int j=i;j<n;j++)
            {
                forward.push_back(s[j]);
                backward.push_front(s[j]);
                cnt+=(forward==backward);
            }
        }
        return cnt;
    }
};