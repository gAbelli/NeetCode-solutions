func jump(nums []int) int {
	n := len(nums)
	if n == 1 {
		return 0
	}

	cur := -1
	res := 0

	for pos := 0; pos < n; pos++ {
		cur--
		if nums[pos] > cur {
			res++
			cur = nums[pos]
		}
		if cur+pos >= n-1 {
			return res
		}
	}

	return res
}

// [1, 2, 0]
