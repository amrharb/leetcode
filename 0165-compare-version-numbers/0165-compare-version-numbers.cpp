class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();
        for (int i = 0, j = 0; i < n || j < m; i++, j++) {
            int v1 = 0, v2 = 0;
            while (i < n && version1[i] != '.') {
                v1 = v1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < m && version2[j] != '.') {
                v2 = v2 * 10 + (version2[j] - '0');
                j++;
            }
            if (v1 != v2)
                return (v1 > v2) * 2 - 1;
        }
        return 0;
    }
};