class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size(),j=0;
        vector<int>arr(n);
        for(int i=(n-k%n)%n;i<n;i++)arr[j++]=nums[i];
        for(int i=0;i<(n-k%n)%n;i++)arr[j++]=nums[i];
        nums=arr;
    }
};