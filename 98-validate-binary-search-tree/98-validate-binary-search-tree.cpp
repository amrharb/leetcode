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
    bool dfs(TreeNode* root,long long mn,long long mx){
        if(root==nullptr)return 1;
        if(root->val>=mx||root->val<=mn)return 0;
        return dfs(root->left,mn,root->val)&&dfs(root->right,root->val,mx);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,-(1LL<<31)-1,(1LL<<31));
    }
};