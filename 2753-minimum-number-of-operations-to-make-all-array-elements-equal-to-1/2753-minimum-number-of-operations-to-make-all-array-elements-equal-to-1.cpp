class Solution {
public:
    int minOperations(vector<int>& nums) {
        int gc = 0;
        for (auto& it : nums)
            gc = __gcd(gc, it);
        if (gc > 1)
            return -1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
            }
        }
        if (cnt)
            return nums.size() - cnt;
        int n = nums.size(), mn = 1e9;
        for (int i = 0; i < n; i++) {
            int gc = 0;
            for (int j = i; j < n; j++) {
                gc = __gcd(gc, nums[j]);
                if (gc == 1) {
                    mn = min(mn, max(0, j - i - 1));
                    break;
                }
            }
        }
        return nums.size() + mn;
    }
};