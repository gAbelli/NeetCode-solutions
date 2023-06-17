#include <iostream>
#include <unordered_map>
#include <vector>

class Node {
  public:
    int val;
    std::vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node *>();
    }
    Node(int _val, std::vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
  public:
    Node *helper(Node *node, std::unordered_map<Node *, Node *> &map) {
        if (!map.count(node)) {
            map[node] = new Node(node->val);
            for (Node *neighbor : node->neighbors) {
                map[node]->neighbors.push_back(helper(neighbor, map));
            }
        }
        return map[node];
    }

    Node *cloneGraph(Node *node) {
        if (!node) {
            return node;
        }
        std::unordered_map<Node *, Node *> map;
        return helper(node, map);
    }
};
