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
        vector<int>par(101);
        while(!q.empty()){
            int sz=q.size();
            int haveX=0,haveY=0;
            while(sz--){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->val==x)haveX=par[cur->val];
                if(cur->val==y)haveY=par[cur->val];
                if(cur->left!=nullptr)
                    q.push(cur->left),par[cur->left->val]=cur->val;
                if(cur->right!=nullptr)
                    q.push(cur->right),par[cur->right->val]=cur->val;
            }
            if(haveX&&haveY&&haveX!=haveY)
                return true;
        }
        return false;
    }
};