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
    ListNode* start;
    bool dfs(TreeNode* root,int val){
        if(root==NULL)return 0;
        if(root->val==val&&(dfs2(start,root)||dfs2(start,root)))return 1;
        return dfs(root->left,val)||dfs(root->right,val);
    }
    bool dfs2(ListNode* head,TreeNode* root){
        if(head==NULL)return 1;
        if(root==NULL)return 0;
        if(head->val==root->val)return (dfs2(head->next,root->left)||dfs2(head->next,root->right));
        return 0;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        start=head;
        return dfs(root,head->val);
    }
};