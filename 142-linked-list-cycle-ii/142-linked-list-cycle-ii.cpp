/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    map<ListNode*,bool>mp;
    ListNode* dfs(ListNode* head,ListNode* last){
        if(head==nullptr)return head;
        if(mp[head])return head;
        mp[head]=1;
        return dfs(head->next,head);
    }
    ListNode *detectCycle(ListNode *head) {
        return dfs(head,nullptr);
    }
};