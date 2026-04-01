class Solution {
public:
    struct item {
        int pos, health, index;
        char dir;
        bool operator<(const item& other) const { return pos < other.pos; }
    };
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<item> items(n);
        for (int i = 0; i < n; i++) {
            items[i].pos = positions[i];
            items[i].health = healths[i];
            items[i].dir = directions[i];
            items[i].index = i;
        }
        sort(items.begin(), items.end());
        stack<item> st;
        vector<item> ans;
        for (int i = 0; i < n; i++) {
            if (items[i].dir == 'L') {
                while (!st.empty()) {
                    auto top = st.top();
                    st.pop();
                    if (top.health == items[i].health) {
                        items[i].health = 0;
                        break;
                    } else if (top.health > items[i].health) {
                        top.health--;
                        items[i].health = 0;
                        st.push(top);
                        break;
                    } else {
                        items[i].health--;
                    }
                }
                if (items[i].health)
                    ans.push_back(items[i]);
            } else
                st.push(items[i]);
        }
        while (!st.empty())
            ans.push_back(st.top()), st.pop();
        vector<pair<int, int>> sol;
        for (auto it : ans)
            sol.push_back({it.index, it.health});
        sort(sol.begin(), sol.end());
        vector<int> a;
        for (auto& it : sol)
            a.push_back(it.second);
        return a;
    }
};