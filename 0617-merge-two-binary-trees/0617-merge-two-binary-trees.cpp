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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr&&root2==nullptr)return nullptr;
        TreeNode* cur=new TreeNode();
        if(root1!=nullptr)cur->val+=root1->val;
        if(root2!=nullptr)cur->val+=root2->val;
        if(root1!=nullptr||root2!=nullptr){
            cur->left=mergeTrees((root1==nullptr ? root1:root1->left),(root2 == nullptr ? root2:root2->left));
            cur->right=mergeTrees((root1==nullptr ? root1:root1->right),(root2 == nullptr ? root2:root2->right));
        }
        return cur;
    }
};