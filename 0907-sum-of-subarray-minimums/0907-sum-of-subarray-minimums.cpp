const int MOD=1e9+7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> left_boundary(n, -1);
        vector<int> right_boundary(n, n);

        // Find the left boundaries
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[i] <= arr[s.top()]) {
                right_boundary[s.top()] = i;
                s.pop();
            }
            left_boundary[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }

        // Calculate the contribution of each element to the final result
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result = (result + static_cast<long long>(arr[i]) * (i - left_boundary[i]) * (right_boundary[i] - i)) % MOD;
        }
        return static_cast<int>(result);
    }
};