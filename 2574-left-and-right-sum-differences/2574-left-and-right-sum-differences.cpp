class Solution {
public:
    vector<int> leftRightDifference(vector<int>& v) {
        int n = v.size();
        vector<int> left(n), right(n), ans(n);
        for (int i = 1; i < n; i++)
            left[i] = left[i - 1] + v[i - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = right[i + 1] + v[i + 1];
        for (int i = 0; i < n; i++)
            ans[i] = abs(right[i] - left[i]);
        return ans;
    }
};