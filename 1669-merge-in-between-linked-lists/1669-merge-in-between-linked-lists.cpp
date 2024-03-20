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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int cnt=a-1;
        ListNode* temp=list1;
        while(temp->next!=nullptr&&cnt--)
            temp=temp->next;
        ListNode* nxt=temp->next;
        temp->next=list2;
        cnt=b-a+1;
        while(nxt->next!=nullptr&&cnt--)
            nxt=nxt->next;
        while(list2->next!=nullptr)
            list2=list2->next;
        list2->next=nxt;
        return list1;
    }
};