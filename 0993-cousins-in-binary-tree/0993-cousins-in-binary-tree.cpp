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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            bool haveX=false,haveY=false;
            while(sz--){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left!=nullptr&&cur->right!=nullptr){
                    int left=cur->left->val,right=cur->right->val;
                    if(min(left,right)==min(x,y)&&max(left,right)==max(x,y))
                        return false;
                }
                if(cur->val==x)haveX=1;
                if(cur->val==y)haveY=1;
                if(cur->left!=nullptr)
                    q.push(cur->left);
                if(cur->right!=nullptr)
                    q.push(cur->right);
            }
            if(haveX&&haveY)
                return true;
        }
        return false;
    }
};