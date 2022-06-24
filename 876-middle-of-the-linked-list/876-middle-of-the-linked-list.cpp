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
    ListNode* middleNode(ListNode* head) {
        ListNode* save=head;
        int cnt1=0,cnt2=0;
        while(head!=nullptr){
            cnt1++;
            head=head->next;
        }
        while(save!=nullptr){
            cnt2++;
            if(cnt1/2+1==cnt2)return save;
            save=save->next;
        }
        return save;
    }
};