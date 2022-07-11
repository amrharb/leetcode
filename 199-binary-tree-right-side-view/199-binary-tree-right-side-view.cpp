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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return {};
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            TreeNode* last;
            while(sz--){
                last=q.front(),q.pop();
                if(last->left!=NULL)q.push(last->left);
                if(last->right!=NULL)q.push(last->right);
            }
            v.push_back(last->val);
        }
        return v;
    }
};