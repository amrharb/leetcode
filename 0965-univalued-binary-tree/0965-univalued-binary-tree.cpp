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
    bool isUnivalTree(TreeNode* root) {
        if(nullptr)return true;
        bool ret=true;
        if(root->left!=nullptr){
            if(root->val!=root->left->val)return false;
            ret&=isUnivalTree(root->left);
        }
        if(root->right!=nullptr){
            if(root->val!=root->right->val)return false;
            ret&=isUnivalTree(root->right);
        }
        return ret;
    }
};