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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy=new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;

        for (int i = 1; i < left; i++) {
            pre = pre->next;
        }

        ListNode* curr = pre->next;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        for (int i = left; i <= right; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        pre->next->next = curr;
        pre->next = prev;

        return dummy->next;
    }
};
