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
    int sumRootToLeaf(TreeNode* root,int cur=0) {
        if(root==nullptr)return 0;
        if(root->left==nullptr&&root->right==nullptr)return cur*2+root->val;
        return sumRootToLeaf(root->left,cur*2+root->val)+sumRootToLeaf(root->right,cur*2+root->val);
    }
};