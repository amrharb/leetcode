class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        for(char ch='a';ch<='z';ch++)
        {
            int mn=1e9;
            for(auto&word:words)
            {
                int cnt=0;
                for(auto&it:word)
                    cnt+=(it==ch);
                mn=min(mn,cnt);
            }
            for(int i=0;i<mn;i++)
            {
                ans.push_back({ch});
            }
        }
        return ans;
    }
};