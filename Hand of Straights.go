import "sort"

func isNStraightHand(hand []int, groupSize int) bool {
	n := len(hand)
	if n == 0 {
		return true
	}
	if n%groupSize != 0 {
		return false
	}

	count := make(map[int]int)
	for _, x := range hand {
		count[x]++
	}

	var keys []int
	for key := range count {
		keys = append(keys, key)
	}

	sort.Ints(keys)

	index := 0
	for {
		if index >= len(keys) {
			break
		}
		min := keys[index]
		if count[min] == 0 {
			index++
			continue
		}
		count[min]--
		for i := min + 1; i < min+groupSize; i++ {
			if count[i] == 0 {
				return false
			}
			count[i]--
		}
	}

	return true
}
