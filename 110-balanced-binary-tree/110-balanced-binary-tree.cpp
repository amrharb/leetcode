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
    bool flag=1;
    int dfs(TreeNode* root){
        if(root==NULL)return 0;
        int left=1+dfs(root->left),right=1+dfs(root->right);
        if(abs(left-right)<=1)return max(left,right);
        flag=0;
        return 0;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        return dfs(root)&&flag;
    }
};