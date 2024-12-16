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
    int dfs(TreeNode* root,int mn,int mx){
        if(root==nullptr)return INT_MAX;
        int cur=min(root->val-mn,mx-root->val);
        cur=min(cur,dfs(root->left,mn,root->val));
        cur=min(cur,dfs(root->right,root->val,mx));
        return cur;
    }
    int getMinimumDifference(TreeNode* root) {
        return dfs(root,-1e5,2e5);
    }
};