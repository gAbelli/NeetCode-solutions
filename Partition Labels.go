package main

func partitionLabels(s string) []int {
	counts := make(map[rune]int)
	for _, c := range s {
		counts[c]++
	}

	res := []int{}
	found := make(map[rune]bool)
	cur := 0
	tot := 0

	for _, c := range s {
		if !found[c] {
			found[c] = true
			tot += counts[c]
		}
		cur++
		if cur == tot {
			res = append(res, cur)
			cur = 0
			tot = 0
			found = make(map[rune]bool)
		}
	}

	return res
}

// abac
// [3, 1]
