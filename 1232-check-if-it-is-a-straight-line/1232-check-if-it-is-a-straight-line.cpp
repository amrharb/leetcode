class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& v) {
        int n=v.size(),dx,dy;
        dx=(v[1][0]-v[0][0]),dy=(v[1][1]-v[0][1]);
        for(int i=2;i<n;i++){
            if((v[i][1]-v[i-1][1])*dx!=(v[i][0]-v[i-1][0])*dy)return 0;
        }
        return 1;
    }
};