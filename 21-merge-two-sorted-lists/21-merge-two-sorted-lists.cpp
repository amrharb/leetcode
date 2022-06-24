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
    ListNode* k;
    void solve(ListNode* list1,ListNode* list2,ListNode* last){
        if(list1==nullptr&&list2==nullptr)return;
        if(list1==nullptr){
            solve(list1,list2->next,list2);
            if(last==nullptr)last=list2;
              else last->next=list2;
            ans=list2;
        }
        else if(list2==nullptr){
            solve(list1->next,list2,list1);
            if(last==nullptr)last=list1;
            else last->next=list1;
            ans=list1;
        }
        else{
            if(list1->val<list2->val){
                solve(list1->next,list2,list1);
                if(last==nullptr)last=list1;
                else last->next=list1;
                ans=list1;
            }
            else{
                solve(list1,list2->next,list2);
                if(last==nullptr)last=list2;
                else last->next=list2;
                ans=list2;
            }
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        k=nullptr;
        solve(list1,list2,k);
        return ans;
    }
};