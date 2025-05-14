class Solution {
public:
    int MOD = 1e9 + 7;

    void multiply(vector<vector<long long>>& A, vector<vector<long long>>& B) {
        vector<vector<long long>> C(26, vector<long long>(26, 0));

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                A[i][j] = C[i][j];
    }

    vector<vector<long long>> power(vector<vector<long long>> M, int expo) {
        vector<vector<long long>> ans(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; i++)
            ans[i][i] = 1;
        while (expo) {
            if (expo & 1)
                multiply(ans, M);
            multiply(M, M);
            expo >>= 1;
        }

        return ans;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<long long>> a(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= nums[i]; j++)
                a[i][(i + j) % 26] = 1;
        }
        vector<vector<long long>> tMatrix = power(a, t);
        vector<long long> ts(26, 0);
        for (int i = 0; i < 26; i++) {
            for (auto val : tMatrix[i])
                ts[i] += val;
        }

        long long ans = 0;
        for (auto ch : s) {
            ans = (ans + ts[ch - 'a']) % MOD;
        }
        return ans;
    }
};