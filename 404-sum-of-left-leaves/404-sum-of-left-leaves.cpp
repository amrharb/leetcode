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
    int dfs(TreeNode* root,bool flag){
        if(root==nullptr)return 0;
        int ans=dfs(root->left,1)+dfs(root->right,0);
        if(flag&&!root->left&&!root->right)ans+=root->val;
        return ans;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root,0);
    }
};