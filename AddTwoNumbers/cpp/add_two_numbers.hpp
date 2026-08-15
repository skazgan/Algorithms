#ifndef ADD_TWO_NUMBERS_HPP
#define ADD_TWO_NUMBERS_HPP

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* curr = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int v2 = (l2 != nullptr) ? l2->val : 0;

            int total = v1 + v2 + carry;
            carry = total / 10;
            int digit = total % 10;

            curr->next = new ListNode(digit);
            curr = curr->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummy.next;
    }
};

inline ListNode* buildList(const std::vector<int>& digits) {
    ListNode dummy;
    ListNode* curr = &dummy;
    for (int d : digits) {
        curr->next = new ListNode(d);
        curr = curr->next;
    }
    return dummy.next;
}

inline std::vector<int> listToVector(ListNode* node) {
    std::vector<int> out;
    while (node != nullptr) {
        out.push_back(node->val);
        node = node->next;
    }
    return out;
}

#endif // ADD_TWO_NUMBERS_HPP
