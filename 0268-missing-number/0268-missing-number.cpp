class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bitset<10001>bs;
        int n=nums.size();
        for(int i=0;i<n;i++)
            bs[nums[i]]=1;
        for(int i=0;i<n;i++)
            if(!bs[i])
                return i;
        return n;
    }
};