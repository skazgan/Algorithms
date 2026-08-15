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
 *
 * Solution and List<->helpers live in add_two_numbers.hpp so this file and
 * tests/test_add_two_numbers.cpp can both use them without a duplicate main().
 */

#include <iostream>
#include "add_two_numbers.hpp"

void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val;
        if (node->next != nullptr) std::cout << " -> ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solver;
    ListNode* l1 = buildList({2, 4, 3});  // 342
    ListNode* l2 = buildList({5, 6, 4});  // 465
    ListNode* result = solver.addTwoNumbers(l1, l2);
    printList(result);                     // 7 -> 0 -> 8
    return 0;
}
