class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), mx = 0, cnt = 0, last = 0;
        for (int i = 0; i + 1 < n; i++) {
            mx = max(mx, i + nums[i]);
            if (i == last) {
                ++cnt;
                last = mx;
            }
        }
        return cnt;
    }
};