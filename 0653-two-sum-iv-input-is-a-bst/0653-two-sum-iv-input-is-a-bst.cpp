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
    bool validate(TreeNode* root,int k,unordered_map<int,int>&freq){
        if(root==nullptr)return false;
        if(freq.count(k-root->val))
            return true;
        freq[root->val]++;
        return validate(root->left,k,freq)||validate(root->right,k,freq);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>freq;
        return validate(root,k,freq);
    }
};