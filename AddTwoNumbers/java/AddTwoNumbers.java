/**
 * Add Two Numbers
 * ----------------
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order (ones digit first), and
 * each node contains a single digit. Add the two numbers and return the sum
 * as a linked list, in the same reversed format.
 *
 * Example:
 *   Input:  l1 = 2 -> 4 -> 3   (represents 342)
 *           l2 = 5 -> 6 -> 4   (represents 465)
 *   Output: 7 -> 0 -> 8        (represents 807)
 *
 * Approach:
 *   Walk both lists at the same time, one node per step, just like adding
 *   two numbers by hand starting from the ones column. Keep a running
 *   carry; a missing node (list already ran out) counts as digit 0. Stop
 *   once both lists are exhausted and there's no carry left.
 *
 * Complexity:
 *   Time:  O(max(n, m)) - one pass over the longer list
 *   Space: O(max(n, m)) - for the output list
 */

public class AddTwoNumbers {

    static class ListNode {
        int val;
        ListNode next;

        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode();
        ListNode curr = dummy;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            int v1 = (l1 != null) ? l1.val : 0;
            int v2 = (l2 != null) ? l2.val : 0;

            int total = v1 + v2 + carry;
            carry = total / 10;
            int digit = total % 10;

            curr.next = new ListNode(digit);
            curr = curr.next;

            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }

        return dummy.next;
    }

    // --- helpers for quick manual testing ---

    static ListNode buildList(int[] digits) {
        ListNode dummy = new ListNode();
        ListNode curr = dummy;
        for (int d : digits) {
            curr.next = new ListNode(d);
            curr = curr.next;
        }
        return dummy.next;
    }

    static String listToString(ListNode node) {
        StringBuilder sb = new StringBuilder();
        while (node != null) {
            sb.append(node.val);
            if (node.next != null) sb.append(" -> ");
            node = node.next;
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        AddTwoNumbers solver = new AddTwoNumbers();
        ListNode l1 = buildList(new int[]{2, 4, 3});  // 342
        ListNode l2 = buildList(new int[]{5, 6, 4});  // 465
        ListNode result = solver.addTwoNumbers(l1, l2);
        System.out.println(listToString(result));      // 7 -> 0 -> 8
    }
}
