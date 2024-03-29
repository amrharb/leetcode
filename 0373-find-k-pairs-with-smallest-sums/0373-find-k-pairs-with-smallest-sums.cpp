class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> ans;
        set<pair<int, int>> vis;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> q;
        q.push({nums1[0] + nums2[0], {0, 0}});
        vis.insert({0, 0});

        while (k-- && !q.empty()) {
            auto top = q.top();
            q.pop();
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if (i + 1 < m && vis.find({i + 1, j}) == vis.end()) {
                q.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                vis.insert({i + 1, j});
            }

            if (j + 1 < n && vis.find({i, j + 1}) == vis.end()) {
                q.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                vis.insert({i, j + 1});
            }
        }

        return ans;
    }
};