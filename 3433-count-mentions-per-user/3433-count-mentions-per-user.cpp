class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(), events.end(),
             [&](vector<string> a, vector<string> b) {
                 if (stoi(a[1]) == stoi(b[1])) {
                     if (a[0] == "OFFLINE")
                         return 1;
                     return 0;
                 }
                 return int(stoi(a[1]) < stoi(b[1]));
             });
        vector<int> ans(n, 0), online(n, 1), ret(n, -1e9);
        for (auto e : events) {
            string type = e[0];
            int t = stoi(e[1]);
            if (type == "OFFLINE") {
                int id = stoi(e[2]);
                online[id] = false;
                ret[id] = t + 60;
            } else if (type == "MESSAGE") {
                auto s = e[2];
                for (int i = 0; i < n; i++) {
                    if (ret[i] <= t) {
                        online[i] = true;
                    }
                }

                if (s == "ALL") {
                    for (int i = 0; i < n; i++) {
                        ans[i]++;
                    }
                } else if (s == "HERE") {
                    for (int i = 0; i < n; i++) {
                        if (online[i]) {
                            ans[i]++;
                        }
                    }
                } else {
                    stringstream ss(s);
                    while (ss >> s) {
                        int id = stoi(s.substr(2));
                        ans[id]++;
                    }
                }
            }
        }
        return ans;
    }
};