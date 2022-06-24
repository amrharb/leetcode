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
    void solve(ListNode* head,ListNode* &last,int k){
        if(head==nullptr){
            if(last==nullptr)last=head;
            else last->next=head;
            return;
        }
        if(head->val==k)solve(head->next,last,k);
        else {
            if(last==nullptr)last=head;
            else last->next=head;
            solve(head->next,head,k);
        }
    }
    ListNode* removeElements(ListNode* head, int k) {
        if(head==nullptr)return head;
        ListNode* last=nullptr;
        solve(head,last,k);
        return last;
    }
};