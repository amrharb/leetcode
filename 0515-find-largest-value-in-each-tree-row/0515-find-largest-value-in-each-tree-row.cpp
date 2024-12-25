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
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr)return {};
        vector<int>largeVals;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size(),mx=INT_MIN;
            while(sz--){
                auto p=q.front();
                q.pop();
                mx=max(mx,p->val);
                if(p->left!=nullptr)
                    q.push(p->left);
                if(p->right!=nullptr)
                    q.push(p->right);
            }
            largeVals.push_back(mx);
        }
        return largeVals;
    }
};