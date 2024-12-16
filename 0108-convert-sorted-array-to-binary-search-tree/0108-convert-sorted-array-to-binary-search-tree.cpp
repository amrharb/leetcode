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
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        if(nums.empty())return nullptr;
        auto left = sortedArrayToBST(vector<int>(nums.begin(),nums.begin()+nums.size()/2));
        auto right = sortedArrayToBST(vector<int>(nums.begin()+nums.size()/2+1,nums.end()));
        TreeNode* root = new TreeNode(nums[nums.size()/2],left,right);
        return root;
    }
};