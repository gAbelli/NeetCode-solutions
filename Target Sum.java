import java.util.HashMap;
import java.util.Map;

class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        Map<Integer, Integer> ways = new HashMap<>();
        ways.put(0, 1);

        for (int x : nums) {
            Map<Integer, Integer> newWays = new HashMap<>();
            for (Map.Entry<Integer, Integer> entry : ways.entrySet()) {
                int sumWithPlus = entry.getKey() + x;
                int sumWithMinus = entry.getKey() - x;

                if (newWays.containsKey(sumWithPlus)) {
                    newWays.put(sumWithPlus,
                                newWays.get(sumWithPlus) + entry.getValue());
                } else {
                    newWays.put(sumWithPlus, entry.getValue());
                }

                if (newWays.containsKey(sumWithMinus)) {
                    newWays.put(sumWithMinus,
                                newWays.get(sumWithMinus) + entry.getValue());
                } else {
                    newWays.put(sumWithMinus, entry.getValue());
                }
            }

            ways = newWays;
        }

        if (!ways.containsKey(target)) {
            return 0;
        }

        return ways.get(target);
    }
}
