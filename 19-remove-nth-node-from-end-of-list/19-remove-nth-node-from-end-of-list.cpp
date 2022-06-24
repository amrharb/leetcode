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
    ListNode* ans;
    void solve(ListNode* head,ListNode* last,int i){
        if(!i){
            if(last==nullptr){
                last=head->next;
                ans=last;
                return;
            }
            else {
                last->next=head->next;
                return;
            }
        }
        solve(head->next,head,i-1);
        ans=head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* save=head;
        int cnt=0;
        while(head!=nullptr){
            cnt++;
            head=head->next;
        }
        solve(save,head,cnt-n);
        return ans;
    }
};