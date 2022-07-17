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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* seq=new ListNode(0,head);
        ListNode* par=seq;
        while(head!=NULL){
            if(head->next!=NULL&&head->val==head->next->val){
                 while(head->next!=NULL&&head->val==head->next->val){
                     head=head->next;
                 }
                par->next=head->next;
            }
            else{
                par=par->next;
            }
            head=head->next;
        }
        return seq->next;
    }
};