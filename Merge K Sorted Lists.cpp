#include <iostream>
#include <queue>
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
    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
        auto cmp = [&](int x, int y) { return lists[x]->val > lists[y]->val; };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> queue(cmp);

        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                queue.push(i);
            }
        }

        ListNode dummy;
        ListNode *cur = &dummy;
        while (!queue.empty()) {
            int n = queue.top();
            queue.pop();
            cur->next = lists[n];
            lists[n] = lists[n]->next;
            cur = cur->next;
            if (lists[n]) {
                queue.push(n);
            }
        }
        return dummy.next;
    }
};
