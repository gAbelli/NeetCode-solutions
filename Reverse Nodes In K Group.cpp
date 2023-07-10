struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head) {
            return nullptr;
        }
        ListNode *right = head;
        ListNode *prev = nullptr;
        int i = k;
        while (right && i != 0) {
            prev = right;
            right = right->next;
            i--;
        }
        if (i != 0) {
            return head;
        }
        prev->next = nullptr;

        ListNode *nextList = reverseKGroup(right, k);

        prev = nullptr;
        ListNode *cur = head;
        ListNode *next = head;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        head->next = nextList;
        return prev;
    }
};
