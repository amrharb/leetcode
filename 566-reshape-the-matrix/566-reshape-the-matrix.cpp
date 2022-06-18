class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r*c!=mat.size()*mat[0].size())return mat;
        int x=0;
        vector<vector<int>>v(r);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                v[x].push_back(mat[i][j]);
                if(v[x].size()==c)x++;
            }
        }
        return v;
    }
};