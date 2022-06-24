/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool>mp;
        while(head!=nullptr){
            if(mp[head])return 1;
            mp[head]=1;
            head=head->next;
        }
        return 0;
    }
};