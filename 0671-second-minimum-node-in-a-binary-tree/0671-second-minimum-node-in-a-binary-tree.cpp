class Solution {
public:
    long secondMin = LONG_MAX;
    void dfs(TreeNode* root, int minVal) {
        if (!root) return;
        if (root->val > minVal && root->val < secondMin) {
            secondMin = root->val;
        } else if (root->val == minVal) {
            dfs(root->left, minVal);
            dfs(root->right, minVal);
        }
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1; 
        dfs(root, root->val);
        return (secondMin == LONG_MAX) ? -1 : secondMin;
    }
};
