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
    void dfs(TreeNode* root,unordered_map<int,int>&freq,int &mx,vector<int>&modes){
        if(root==nullptr)return;
        freq[root->val]++;
        if(freq[root->val]==mx)
            modes.push_back(root->val);
        else if(freq[root->val]>mx){
            mx=freq[root->val];
            modes={root->val};
        }
        dfs(root->left,freq,mx,modes);
        dfs(root->right,freq,mx,modes);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>modes;
        unordered_map<int,int>freq;
        int mx=0;
        dfs(root,freq,mx,modes);
        return modes;
    }
};