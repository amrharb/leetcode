/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool check(ListNode* head,TreeNode* root){
        if(head==NULL)return 1;
        if(root==NULL)return 0;
        if(head->val==root->val)return (check(head->next,root->left)||check(head->next,root->right));
        return 0;
    }
    bool dfs(ListNode* head,TreeNode* root){
        if(root==NULL||head==NULL)return 0;
        if(root->val==head->val&&(check(head,root)||check(head,root)))return 1;
        return dfs(head,root->left)||dfs(head,root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head,root);
    }
};