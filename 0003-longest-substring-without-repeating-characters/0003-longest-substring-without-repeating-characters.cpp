class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0,n=s.size(),mx=0;
        unordered_map<char,int>vis;
        while(left<n){
            while(right<n&&!vis[s[right]]){
                vis[s[right]]=1;
                right++;
            }
            mx=max(mx,right-left);
            vis[s[left]]=0;
            left++;
        }
        return mx;
    }
};