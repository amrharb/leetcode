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
    int count(ListNode* cur,int i){
        if(cur==nullptr)return 0;
        return (cur->val==1 ? (1<<i):0)+count(cur->next,i+1);
    }
    int getDecimalValue(ListNode* head) {
         solve(head,nullptr);
        return count(k,0);
    }
};