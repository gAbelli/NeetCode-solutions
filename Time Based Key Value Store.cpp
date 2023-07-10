#include <iostream>
#include <unordered_map>
#include <vector>

class TimeMap {
  public:
    TimeMap() {}

    void set(std::string key, std::string value, int timestamp) {
        if (!map.count(key)) {
            map[key] = {};
        }
        map[key].push_back({value, timestamp});
    }

    std::string get(std::string key, int timestamp) {
        std::vector pairs = map[key];
        if (pairs.empty() || timestamp < pairs[0].second) {
            return "";
        }
        int left = 0;
        int right = pairs.size() - 1;
        while (left < right) {
            int mid = std::ceil((double)(left + right) / 2);
            if (pairs[mid].second == timestamp) {
                return pairs[mid].first;
            }
            if (pairs[mid].second > timestamp) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return pairs[left].first;
    }

  private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>
        map;
};
