# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = ListNode(0)
        dummy = prev
        while head and head.next:
            temp = head.next
            head.next = temp.next
            temp.next = head
            dummy.next = temp
            dummy = dummy.next.next
            head = head.next
        if head:
            dummy.next = head
        return prev.next
