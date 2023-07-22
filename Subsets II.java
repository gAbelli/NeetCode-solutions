import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
		Arrays.sort(nums);
		List<List<Integer>> res = new ArrayList<>();
		List<Integer> cur = new ArrayList<>();
		dfs(nums, res, cur, 0);

		return res;
    }

	private void dfs(int[] nums, List<List<Integer>> res, List<Integer> cur, int index) {
		res.add(new ArrayList<>(cur));

		for (int i = index; i < nums.length; ++i) {
			if (i > index && nums[i] == nums[i-1]) {
				continue;
			}
			cur.add(nums[i]);
			dfs(nums, res, cur, i+1);
			cur.remove(cur.size() - 1);
		}
	}
}
