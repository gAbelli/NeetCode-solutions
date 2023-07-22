import java.util.ArrayList;
import java.util.List;

class Solution {
    public int jump(int[] nums) {
        int zeros = 0;
        for (int i = nums.length - 1; i >= 0; --i) {
            nums[i] -= zeros;
            if (nums[i] == 0) {
                zeros++;
            }
        }

        List<Integer> nonZeros = new ArrayList<>();
        for (int x : nums) {
            if (x != 0) {
                nonZeros.add(x);
            }
        }

        int n = nonZeros.size();
        int[] jumps = new int[n];

        for (int i = n - 2; i >= 0; --i) {
            jumps[i] = 1 + jumps[Math.min(i + nonZeros.get(i), n - 1)];
        }

        return jumps[0];
    }
}
