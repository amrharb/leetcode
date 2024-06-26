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
    int sumOfLeftLeaves(TreeNode* root,bool flag=0) {
        if(root==nullptr)return 0;
        if(!root->left&&!root->right)return flag*root->val;
        return sumOfLeftLeaves(root->left,1)+sumOfLeftLeaves(root->right,0);
    }
};