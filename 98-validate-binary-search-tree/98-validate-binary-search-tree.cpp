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
    bool dfs(TreeNode* root,TreeNode* mn,TreeNode* mx){
        if(root==nullptr)return 1;
        if(mx!=nullptr&&root->val>=mx->val||mn!=nullptr&&root->val<=mn->val)return 0;
        return dfs(root->left,mn,root)&&dfs(root->right,root,mx);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,nullptr,nullptr);
    }
};