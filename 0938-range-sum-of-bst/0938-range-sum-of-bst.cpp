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
private:
    int solve(TreeNode* root,int l,int r){
        if(root==NULL)
            return 0;
        int ans=0;
        if(root->val>=l&&root->val<=r)
            ans=root->val;
        if(root->val>=l)
            ans+=solve(root->left,l,r);
        if(root->val<=r)
            ans+=solve(root->right,l,r);
        return ans;
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root,low,high);
    }
};