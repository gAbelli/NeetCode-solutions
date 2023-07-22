import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> neighbors = new ArrayList<>();
        for (int i = 0; i < numCourses; ++i) {
            neighbors.add(new ArrayList<>());
        }

        int[] prerequisitesNumber = new int[numCourses];
        for (int[] pair : prerequisites) {
            neighbors.get(pair[1]).add(pair[0]);
            prerequisitesNumber[pair[0]]++;
        }

        List<Integer> res = new ArrayList<>();
        Deque<Integer> queue = new LinkedList<>();

        for (int i = 0; i < numCourses; ++i) {
            if (prerequisitesNumber[i] == 0) {
                queue.add(i);
            }
        }

        while (!queue.isEmpty()) {
            int front = queue.poll();
            res.add(front);
            for (int j : neighbors.get(front)) {
                prerequisitesNumber[j]--;
                if (prerequisitesNumber[j] == 0) {
                    queue.add(j);
                }
            }
        }

        if (res.size() != numCourses) {
            return new int[] {};
        }

        int[] resArray = new int[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            resArray[i] = res.get(i);
        }

        return resArray;
    }
}
