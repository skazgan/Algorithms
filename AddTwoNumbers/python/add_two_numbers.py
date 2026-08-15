"""
Add Two Numbers
----------------
You are given two non-empty linked lists representing two non-negative
integers. The digits are stored in reverse order (ones digit first), and
each node contains a single digit. Add the two numbers and return the sum
as a linked list, in the same reversed format.

Example:
    Input:  l1 = 2 -> 4 -> 3   (represents 342)
            l2 = 5 -> 6 -> 4   (represents 465)
    Output: 7 -> 0 -> 8        (represents 807)

Approach:
    Walk both lists at the same time, one node per step, just like adding
    two numbers by hand starting from the ones column. Keep a running
    carry; a missing node (list already ran out) counts as digit 0. Stop
    once both lists are exhausted and there's no carry left.

Complexity:
    Time:  O(max(n, m)) - one pass over the longer list
    Space: O(max(n, m)) - for the output list
"""

from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        curr = dummy
        carry = 0

        while l1 or l2 or carry:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0

            total = v1 + v2 + carry
            carry, digit = divmod(total, 10)

            curr.next = ListNode(digit)
            curr = curr.next

            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        return dummy.next


# --- helpers for quick manual testing ---

def build_list(digits):
    dummy = ListNode()
    curr = dummy
    for d in digits:
        curr.next = ListNode(d)
        curr = curr.next
    return dummy.next


def list_to_str(node):
    digits = []
    while node:
        digits.append(str(node.val))
        node = node.next
    return " -> ".join(digits)


if __name__ == "__main__":
    l1 = build_list([2, 4, 3])   # 342
    l2 = build_list([5, 6, 4])   # 465
    result = Solution().addTwoNumbers(l1, l2)
    print(list_to_str(result))   # 7 -> 0 -> 8
