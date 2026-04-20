class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int last = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (colors[i] != colors[n - 1]) {
                last = i;
                break;
            }
        }
        int ans = 0;
        for (int i = 0; i <= last; i++) {
            if (colors[i] == colors[n - 1]) {
                ans = max(ans, last - i);
            } else {
                ans = max(ans, n - i - 1);
            }
        }
        return ans;
    }
};