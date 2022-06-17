class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& v) {
        int n=v.size(),mx=1e9,idx=-1;
        for(int i=0;i<n;i++){
            if(v[i][0]==x||v[i][1]==y){
                if(abs(v[i][0]-x)+abs(v[i][1]-y)<mx){
                    mx=abs(v[i][0]-x)+abs(v[i][1]-y);
                    idx=i;
                }
            }
        }
        return idx;
    }
};