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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>cur,nxt={root->val};
        bool odd=0;
        while(!q.empty()){
            int sz=q.size();
            cur=nxt;
            nxt.clear();
            while(sz--){
                auto p=q.front();
                q.pop();
                if(odd&1){
                    p->val=cur.back();
                    cur.pop_back();
                }
                if(p->left!=nullptr)
                    q.push(p->left),nxt.push_back(p->left->val);
                if(p->right!=nullptr)
                    q.push(p->right),nxt.push_back(p->right->val);
            }
            odd^=1;
        }
        return root;
    }
};