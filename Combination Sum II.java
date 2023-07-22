import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        dfs(candidates, target, res, cur, 0, 0);

        return res;
    }

    private void dfs(int[] candidates, int target, List<List<Integer>> res,
                     List<Integer> cur, int sum, int index) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.add(new ArrayList<>(cur));
            return;
        }

        for (int i = index; i < candidates.length; ++i) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            cur.add(candidates[i]);
            dfs(candidates, target, res, cur, sum + candidates[i], i + 1);
            cur.remove(cur.size() - 1);
        }
    }
}
