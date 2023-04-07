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
    int sum_of_all(TreeNode* root){
        if(root==NULL)
            return 0;
        return root->val+sum_of_all(root->left)+sum_of_all(root->right);
    }
    int sumLessX(TreeNode* root,int x){
        if(root==NULL)
            return 0;
        return (root->val<x)*root->val+sumLessX(root->left,x)+sumLessX(root->right,x);
    }
    int sumGreaterX(TreeNode* root,int x){
        if(root==NULL)
            return 0;
        return (root->val>x)*root->val+sumGreaterX(root->left,x)+sumGreaterX(root->right,x);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return sum_of_all(root)-sumLessX(root,low)-sumGreaterX(root,high);
    }
};