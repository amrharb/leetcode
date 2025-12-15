# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        head = ListNode(0)
        dummy = head
        index = 0
        for lst in lists:
            if lst:
                heapq.heappush(heap, (lst.val, index, lst))
                index += 1
        while heap:
            val, idx, smallest = heapq.heappop(heap)
            dummy.next = smallest
            dummy = dummy.next
            if smallest.next:
                nxt = smallest.next
                heapq.heappush(heap, (nxt.val, idx, nxt))
        return head.next
