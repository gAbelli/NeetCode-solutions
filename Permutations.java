import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> permute(int[] nums) {
		List<List<Integer>> res = new ArrayList<>();
		dfs(nums, res, 0);

		return res;
    }

	private void dfs(int[] nums, List<List<Integer>> res, int index) {
		if (index == nums.length) {
			List<Integer> cur = new ArrayList<>();
			for (int i : nums) {
				cur.add(i);
			}
			res.add(cur);
			return;
		}

		for (int i = index; i < nums.length; ++i) {
			int tmp = nums[i];
			nums[i] = nums[index];
			nums[index] = tmp;

			dfs(nums, res, index + 1);

			tmp = nums[i];
			nums[i] = nums[index];
			nums[index] = tmp;
		}
	}
}
