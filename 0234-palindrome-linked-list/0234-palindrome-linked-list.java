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
    public ListNode reverseList(ListNode head) {
        ListNode last=null;
        ListNode cur=head;
        ListNode nxt=null;
        while(cur!=null){
            nxt=cur.next;
            cur.next=last;
            last=cur;
            cur=nxt;
        }
        return last;
    }
    public boolean isPalindrome(ListNode head) {
        ListNode temp=head;
        ListNode reversed=new ListNode(0);
        ListNode org=reversed;
        while(temp!=null){
            reversed.next=new ListNode(temp.val);
            temp=temp.next;
            reversed=reversed.next;
        }
        reversed=org.next;
        reversed=reverseList(reversed);
         while(head!=null&&reversed!=null){
            if(head.val!=reversed.val)return false;
            System.out.println(head.val+reversed.val);
            head=head.next;
            reversed=reversed.next;
        }
        return true;
    }
}