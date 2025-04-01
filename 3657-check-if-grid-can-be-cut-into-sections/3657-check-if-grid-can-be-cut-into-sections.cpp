class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> v1, v2, v3, v4;
        int sz = rectangles.size();
        for (int i = 0; i < sz; i++) {
            v1.push_back({rectangles[i][0], rectangles[i][2]});
            v2.push_back({rectangles[i][1], rectangles[i][3]});
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for (int i = 0; i < sz; i++) {
            if (v3.empty() or v1[i].first >= v3.back().second)
                v3.push_back(v1[i]);
            else
                v3.back().second = max(v3.back().second, v1[i].second);
        }

        for (int i = 0; i < sz; i++) {
            if (v4.empty() or v2[i].first >= v4.back().second)
                v4.push_back(v2[i]);
            else
                v4.back().second = max(v4.back().second, v2[i].second);
        }

        return v3.size() > 2 || v4.size() > 2;
    }
};