class Solution {
public:
    int totalMoney(int n) {
        int ans = 0, st = 1, curr = 1;
        for (int i = 1; i <= n; i++) {
            ans += curr;
            if (i % 7 == 0)
                st++, curr = st;
            else
                curr++;
        }
        return ans;
    }
};