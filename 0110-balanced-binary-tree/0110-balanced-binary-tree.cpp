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
    int validate(TreeNode* root,bool &balanced){
        if(root==nullptr)return 0;
        int left=validate(root->left,balanced);
        int right=validate(root->right,balanced);
        if(abs(left-right)>1)
            balanced=0;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        bool balanced=1;
        validate(root,balanced);
        return balanced;
    }
};