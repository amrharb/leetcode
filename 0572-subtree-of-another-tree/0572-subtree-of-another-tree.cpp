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
    bool isSubtree(TreeNode* root, TreeNode* subRoot,bool start=0) {
        if(root==nullptr||subRoot==nullptr)return subRoot==root;
        if(!start&&(isSubtree(root->left,subRoot,0)||isSubtree(root->right,subRoot,0)))return true;
        if(root->val==subRoot->val){
            if(isSubtree(root->left,subRoot->left,1)&&isSubtree(root->right,subRoot->right,1)){
                return true;
            }
        }
        return false;
    }
};