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
    bool compareTo(TreeNode* root1,TreeNode* root2){
        if(!root1&&!root2)return true;
        if(!root1||!root2||root1->val!=root2->val)return false;
        return compareTo(root1->left,root2->right)&&compareTo(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return compareTo(root->left,root->right);
    }
};