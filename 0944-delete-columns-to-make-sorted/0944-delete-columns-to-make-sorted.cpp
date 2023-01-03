class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(),m=strs[0].size(),ans=0;
        for(int i=0;i<m;i++){
            bool flag=0;
            for(int j=1;j<n;j++){
                flag|=(strs[j][i]<strs[j-1][i]);
            }
            ans+=flag;
        }
        return ans;
    }
};