class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans=0,cur_rung=0;
        for(int rung:rungs){
            ans+=(rung-cur_rung-1)/dist;
            cur_rung=rung;
        }
        return ans;
    }
};