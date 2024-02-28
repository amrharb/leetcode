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
    int mxLen(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(mxLen(root->left),mxLen(root->right))+1;
    }
    TreeNode* getLeftMost(TreeNode*root,int rem)
    {
        if(!root||!rem)
            return root;
        TreeNode* cur=getLeftMost(root->left,rem-1);
        if(cur)
            return cur;
        return getLeftMost(root->right,rem-1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int len=mxLen(root)-1;
        TreeNode* ans=getLeftMost(root,len);
        int val=(ans->val);
        return val;
    }
};