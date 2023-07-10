#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy;
        ListNode *cur = &dummy;

        bool carry = false;
        while (l1 || l2) {
            int res = 0;
            if (l1) {
                res += l1->val;
            }
            if (l2) {
                res += l2->val;
            }
            if (carry) {
                res += 1;
            }
            carry = false;

            if (res > 9) {
                res -= 10;
                carry = true;
            }

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            cur->next = new ListNode(res);
            cur = cur->next;
        }
        if (carry) {
            cur->next = new ListNode(1);
        }

        return dummy.next;
    }
};
