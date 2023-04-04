class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(target>=nums[0]){
            int l=0,r=n-1;
            while(l<=r){
                int mid=(l+r)>>1;
                if(nums[mid]>=nums[0]&&nums[mid]<=target){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            if(l-1>=0&&nums[l-1]==target)return l-1;
            return -1;
        }
        else{
            int l=0,r=n-1;
            while(l<=r){
                int mid=l+r>>1;
                if(nums[mid]>=nums[0]){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            r=n-1;
            while(l<=r){
                int mid=l+r>>1;
                if(nums[mid]<=target){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            if(l-1>=0&&nums[l-1]==target) return l-1;
            else return -1;
        }
        return -1;
    }
};