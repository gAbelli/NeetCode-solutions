#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<std::string>>
    groupAnagrams(std::vector<std::string> &strs) {
        std::unordered_map<std::string, std::vector<std::string>> res_map;
        for (const std::string &s : strs) {
            std::string sorted_s = s;
            std::sort(sorted_s.begin(), sorted_s.end());
            if (res_map.count(sorted_s)) {
                res_map[sorted_s].push_back(s);
            } else {
                res_map[sorted_s] = std::vector<std::string>{s};
            }
        }

        std::vector<std::vector<std::string>> res;
        for (const auto &pair : res_map) {
            res.push_back(pair.second);
        }

        return res;
    }
};
