class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int mxFreq = 0, dominant;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            if (++freq[nums[i]] > mxFreq)
                mxFreq++, dominant = nums[i];
        }
        int cnt = 0;
        for (int i = 0; i + 1 < n; i++) {
            cnt += (nums[i] == dominant);
            if (cnt > (i + 1) / 2 && mxFreq - cnt > (n - i - 1) / 2)
                return i;
        }
        return -1;
    }
};