#include <iostream>
#include <vector>

class Solution {
  public:
    void dfs(std::vector<std::vector<int>> &heights,
             std::vector<std::vector<bool>> &visited, int i, int j) {
        visited[i][j] = true;

        int height = heights[i][j];

        if (i + 1 < heights.size() && !visited[i + 1][j] &&
            heights[i + 1][j] >= height) {
            dfs(heights, visited, i + 1, j);
        }
        if (i - 1 >= 0 && !visited[i - 1][j] && heights[i - 1][j] >= height) {
            dfs(heights, visited, i - 1, j);
        }
        if (j + 1 < heights[0].size() && !visited[i][j + 1] &&
            heights[i][j + 1] >= height) {
            dfs(heights, visited, i, j + 1);
        }
        if (j - 1 >= 0 && !visited[i][j - 1] && heights[i][j - 1] >= height) {
            dfs(heights, visited, i, j - 1);
        }
    }

    std::vector<std::vector<int>>
    pacificAtlantic(std::vector<std::vector<int>> &heights) {
        std::vector<std::vector<bool>> visited_atlantic(
            heights.size(), std::vector<bool>(heights[0].size()));
        std::vector<std::vector<bool>> visited_pacific(
            heights.size(), std::vector<bool>(heights[0].size()));

        for (int i = 0; i < heights.size(); ++i) {
            dfs(heights, visited_atlantic, i, 0);
            dfs(heights, visited_pacific, i, heights[0].size() - 1);
        }
        for (int j = 0; j < heights[0].size(); ++j) {
            dfs(heights, visited_atlantic, 0, j);
            dfs(heights, visited_pacific, heights.size() - 1, j);
        }

        std::vector<std::vector<int>> res;
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = 0; j < heights[0].size(); ++j) {
                if (visited_atlantic[i][j] && visited_pacific[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
