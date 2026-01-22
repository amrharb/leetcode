class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while (!is_sorted(nums.begin(), nums.end())) {
            int n = nums.size(), mx = 0;
            for (int i = 0; i + 1 < n; i++) {
                if (nums[i] + nums[i + 1] < nums[mx] + nums[mx + 1]) {
                    mx = i;
                }
            }
            nums[mx] += nums[mx + 1];
            nums.erase(nums.begin() + mx + 1);
            cnt++;
        }
        return cnt;
    }
};