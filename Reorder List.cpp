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
    void reorderList(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *second_half = reverseList(slow->next);
        slow->next = nullptr;
        mergeTwoLists(head, second_half);
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next = head;

        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode dummy;
        ListNode *cur = &dummy;
        while (list1 && list2) {
            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;

            cur->next = list2;
            list2 = list2->next;
            cur = cur->next;
        }
        if (!list1) {
            cur->next = list2;
        } else {
            cur->next = list1;
        }

        return dummy.next;
    }
};
