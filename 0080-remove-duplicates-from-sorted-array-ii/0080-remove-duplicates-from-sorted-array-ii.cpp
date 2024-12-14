class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=2,j=2,n=nums.size();
        while(i<n){
            if(nums[i]!=nums[j-2]){
                nums[j]=nums[i];
                j++;
            }
            i++;
        }
        return min(n,j);
    }
};