class Solution {
public:
    int maximumLength(vector<int>& v) {
        unordered_map<int, int> mp;
        int n = v.size();
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
            mp[v[i]]++;
        int mx = 0;
        for (auto& [a, b] : mp) {
            if (a == 1)
                continue;
            int cnt = 0;
            unsigned long long x = a;
            while (mp.find(x) != mp.end()) {
                cnt += 2;
                if (mp[x] == 1)
                    break;
                x *= x;
            }
            cnt--;
            mx = max(mx, cnt);
        }
        mx = max(mx, mp[1] - !(mp[1] & 1));
        return mx;
    }
};