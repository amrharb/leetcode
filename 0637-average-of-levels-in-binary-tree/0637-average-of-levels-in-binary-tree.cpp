/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> avg;
    vector<int> cnt;

    void dfs(TreeNode* root, int depth) {
        if (root == nullptr) return;
        if (avg.size() <= depth) {
            avg.push_back(0);
            cnt.push_back(0);
        }
        avg[depth] += root->val;
        cnt[depth]++;
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr) return {};
        dfs(root, 0);
        for (int i = 0; i < avg.size(); i++)
            avg[i] /= cnt[i];
        return avg;
    }
};
