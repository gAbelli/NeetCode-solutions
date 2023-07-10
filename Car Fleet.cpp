#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

class Solution {
  public:
    int carFleet(int target, std::vector<int> &position,
                 std::vector<int> &speed) {

        std::vector<int> indices(position.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(),
                  [&](int i, int j) { return position[i] > position[j]; });

        double max_time = 0;
        int res = 0;
        for (int i = 0; i < position.size(); ++i) {
            double curr_time = (double)(target - position[indices[i]]) /
                               (double)speed[indices[i]];
            if (curr_time > max_time) {
                res++;
                max_time = curr_time;
            }
        }

        return res;
    }
};
