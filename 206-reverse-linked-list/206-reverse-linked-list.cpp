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
    ListNode *k;
    void solve(ListNode* head,ListNode *last){
        if(head==nullptr){
            k=last;
            return;
        }
        solve(head->next,head);
        head->next=last;
    }
    ListNode* reverseList(ListNode* head) {
        solve(head,nullptr);
        return k;
    }
};