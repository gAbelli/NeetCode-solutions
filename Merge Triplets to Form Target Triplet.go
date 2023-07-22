func mergeTriplets(triplets [][]int, target []int) bool {
	cur := []int{0, 0, 0}

	for _, t := range triplets {
		if t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2] {
			for i := 0; i < 3; i++ {
				if t[i] >= cur[i] {
					cur[i] = t[i]
				}
			}
		}
	}

	return cur[0] == target[0] && cur[1] == target[1] && cur[2] == target[2]
}
