class Solution {
public:
    int maxDepth(string s) {
        int cnt=0,mx=0;
        for(auto&it:s)
        {
            if(it=='(')
                cnt++;
            else if(it==')')
                cnt--;
            mx=max(mx,cnt);
        }
        return mx;
    }
};