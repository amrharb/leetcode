class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(),my_num,cnt=0;
        for(int i=0;i<n;i++){
            if(!cnt)my_num=nums[i];
            cnt+=(nums[i]==my_num ? 1:-1);
        }
        return my_num;
    }
};