/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1==null&&list2==null)return null;
        if(list1==null)return list2;
        if(list2==null)return list1;
        if(list1.val<list2.val){
            ListNode cur=list1;
            cur.next=mergeTwoLists(list1.next,list2);
            return cur;
        }
        ListNode cur=list2;
        cur.next=mergeTwoLists(list1,list2.next);
        return cur;
    }
}