const int N = 1e5 + 5, mod = 1e9 + 7;
class Solution {
public:
    vector<int> sieve(int n) {
        bitset<N> prime;
        prime.set();
        vector<int> lpf(n + 1);
        iota(lpf.begin(), lpf.end(), 0);
        for (int i = 2, d = 1; i <= n; i += d, d = 2) {
            if (!prime[i])
                continue;
            for (int j = 2 * i; j <= n; j += i) {
                prime[j] = 0;
                lpf[j] = min(lpf[j], i);
            }
        }
        return lpf;
    }
    int bpow(long long n, int x) {
        return !x ? 1 : bpow(n * n % mod, x >> 1) * (x & 1 ? n : 1) % mod;
    }
    int maximumScore(vector<int>& nums, int k) {
        auto lpf = sieve(*max_element(nums.begin(), nums.end()));
        int n = nums.size();
        vector<int> score(n);
        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            while (temp > 1) {
                int spf = lpf[temp];
                while (temp % spf == 0)
                    temp /= spf;
                score[i]++;
            }
        }
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int x, const int y) {
            if (score[x] == score[y])
                return x < y;
            return score[x] > score[y];
        });
        set<int> taken = {-1, n};
        vector<pair<int, long long>> possible;
        for (int i = 0; i < n; i++) {
            int prv = *(--taken.lower_bound(order[i]));
            int nxt = *(taken.upper_bound(order[i]));
            possible.push_back(
                {nums[order[i]], 1LL * (order[i] - prv) * (nxt - order[i])});
            taken.insert(order[i]);
        }
        sort(possible.rbegin(), possible.rend());
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            int take = min((long long)k, possible[i].second);
            ans = 1LL * ans * bpow(possible[i].first, take) % mod;
            k -= take;
        }
        return ans;
    }
};