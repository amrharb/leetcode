class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),mx=0;
        for(int i=0;i<n;i++){
            if(i>mx)
                return 0;
            mx=max(mx,i+nums[i]);
        }
        return 1;
    }
};