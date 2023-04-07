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
private:
    vector<int>values;
    void get_values(TreeNode* root){
        if(root==NULL)
            return;
        values.push_back(root->val);
        get_values(root->left);
        get_values(root->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        get_values(root);
        sort(values.begin(),values.end());
        root=new TreeNode(values[0]);
        TreeNode* temp=root;
        for(int i=1;i<values.size();i++){
            root->right=new TreeNode(values[i]);
            root=root->right;
        }
        return temp;
    }
};