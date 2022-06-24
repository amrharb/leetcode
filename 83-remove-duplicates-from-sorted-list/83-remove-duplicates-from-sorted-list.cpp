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
class Solution {
public:
    void solve(ListNode* head,ListNode* last){
        if(head==nullptr){
            last->next=nullptr;
            return;
        }
        if(head->val==last->val)solve(head->next,last);
        else {
            last->next=head;
            solve(head->next,head);
        }
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)return head;
        solve(head->next,head);
        return head;
    }
};