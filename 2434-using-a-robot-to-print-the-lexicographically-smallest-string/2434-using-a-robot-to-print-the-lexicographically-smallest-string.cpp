class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        string temp = s;
        vector<char> rightmin(n, 'z');
        rightmin[n-1] = s[n-1];
        for(int i = n-2; i>=0; i--)
        {
            rightmin[i] = min(s[i], rightmin[i+1]);
        }
        
        string t = "", p = "";
        for(int i = 0; i<n; i++)
        {
            while(t.size() && t.back() <= s[i] && t.back() <= rightmin[i])
                {
                    p += t.back();
                    t.pop_back();
                }
                t += s[i];
        }
        while(t.size()){
            p += t.back();
            t.pop_back();
        }
        return p;
    }
};