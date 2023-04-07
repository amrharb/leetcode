/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* Helper(TreeNode* cur,TreeNode* copy,TreeNode* target){
        if(cur==target||cur==NULL)
            return copy;
        TreeNode* ans=Helper(cur->left,copy->left,target);
        if(ans!=NULL)
            return ans;
        return Helper(cur->right,copy->right,target);
    }
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return Helper(original,cloned,target);
    }
};