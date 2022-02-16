# 解説AC3,Python解

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pre, pre.next = self, head
        while pre.next and pre.next.next:
            p = pre.next
            q = p.next
            pre.next, q.next, p.next = q, p, q.next
            pre = p
        return self.next
