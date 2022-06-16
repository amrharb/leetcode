class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>v=nums;
        for(auto&it:v)it*=it;
        sort(v.begin(),v.end());
        return v;
    }
};