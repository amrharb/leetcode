class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int index = q.front();
            q.pop();
            if (arr[index] == 0)
                return true;
            int prev = index - arr[index];
            if (prev >= 0 && !visited[prev]) {
                q.push(prev);
                visited[prev] = true;
            }
            int next = index + arr[index];
            if (next < n && !visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
        return false;
    }
};