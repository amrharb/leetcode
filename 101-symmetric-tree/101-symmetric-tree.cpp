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
    bool dfs(TreeNode* sub1,TreeNode* sub2){
        if(sub1==nullptr||sub2==nullptr)return (sub1==nullptr&&sub2==nullptr);
        return (sub1->val==sub2->val&&dfs(sub1->left,sub2->right)&&dfs(sub1->right,sub2->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return 1;
        return dfs(root->left,root->right);
    }
};