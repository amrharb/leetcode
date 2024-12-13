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
    public ListNode removeElements(ListNode head, int val) {
        if(head==null)return head;
        ListNode cur=head;
        while(cur.next!=null){
            if(cur.next.val==val)
                cur.next=cur.next.next;
            else
                cur=cur.next;
        }
        if(head.val==val)
            head=head.next;
        return head;
    }
}