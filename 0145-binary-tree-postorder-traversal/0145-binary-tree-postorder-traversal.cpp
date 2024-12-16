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
    void dfs(TreeNode* root,vector<int>&postorder){
        if(root==nullptr)return;
        dfs(root->left,postorder);
        dfs(root->right,postorder);
        postorder.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        dfs(root,postorder);
        return postorder;
    }
};