class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int,int>>st;
        int n=mat.size();
        for(int i=0;i<n;i++){
            st.insert({count(mat[i].begin(),mat[i].end(),1),i});
        }
        vector<int>ans;
        for(auto it:st){
            ans.push_back(it.second);
            k--;
            if(!k)break;
        }
        return ans;
    }
};