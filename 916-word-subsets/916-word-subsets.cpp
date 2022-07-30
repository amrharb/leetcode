class Solution {
public:
    int mp[30],mk[10000][30],mx[30];
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n=words1.size(),m=words2.size();
        for(int i=0;i<m;i++){
            for(auto&it:words2[i])mp[it-'a']++;
            for(int k=0;k<26;k++)mx[k]=max(mx[k],mp[k]),mp[k]=0;
        }
        for(int i=0;i<n;i++){
            for(auto&it:words1[i])mk[i][it-'a']++;
        }
        vector<string>ans;
        for(int i=0;i<n;i++){
            bool flag=1;
            for(int k=0;k<26;k++){
                if(mx[k]>mk[i][k])flag=0;
            }
            if(flag)ans.push_back(words1[i]);
        }
        return ans;
    }
};