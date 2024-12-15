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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        int carry=0;
        while(l1!=nullptr&&l2!=nullptr){
            int sum=(l1->val+l2->val+carry);
            temp->next=new ListNode(sum%10);
            carry=sum/10;
            l1=l1->next;
            l2=l2->next;
            temp=temp->next;
        }
        while(l1!=nullptr){
            int sum=(l1->val+carry);
            temp->next=new ListNode(sum%10);
            carry=sum/10;
            l1=l1->next;
            temp=temp->next;
        }
        while(l2!=nullptr){
            int sum=l2->val+carry;
            temp->next=new ListNode(sum%10);
            carry=sum/10;
            l2=l2->next;
            temp=temp->next;
        }
        while(carry){
            temp->next=new ListNode(carry%10);
            carry/=10;
        }
        return head->next;
    }
};