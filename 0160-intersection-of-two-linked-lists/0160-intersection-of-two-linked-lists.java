/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode first=headA;
        ListNode second=headB;
        int n=0,m=0;
        while(first!=null){
            n++;
            first=first.next;
        }
        while(second!=null){
            m++;
            second=second.next;
        }
        if(m>n){
            int temp=m;
            m=n;
            n=temp;
            ListNode tempNode=headA;
            headA=headB;
            headB=tempNode;
        }
        first=headA;
        second=headB;
        while(n>m){
            first=first.next;
            n--;
        }
        while(first!=null){
            if(first==second)return first;
            first=first.next;
            second=second.next;
        }
        return null;
    }
}