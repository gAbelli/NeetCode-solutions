package main

// type Pair struct {
// 	index, open int
// }
//
// func checkValidString(s string) bool {
// 	memo := make(map[Pair]bool)
// 	return compute(s, 0, 0, memo)
// }
//
// func compute(s string, index int, open int, memo map[Pair]bool) bool {
// 	if index == len(s) {
// 		return open == 0
// 	}
// 	if open < 0 {
// 		res := false
// 		memo[Pair{index, open}] = res
// 		return res
// 	}
//
// 	if yes, ok := memo[Pair{index, open}]; ok {
// 		return yes
// 	}
//
// 	if s[index] == '(' {
// 		res := compute(s, index+1, open+1, memo)
// 		memo[Pair{index, open}] = res
// 		return res
// 	}
// 	if s[index] == ')' {
// 		res := compute(s, index+1, open-1, memo)
// 		memo[Pair{index, open}] = res
// 		return res
// 	}
//
// 	res := compute(s, index+1, open-1, memo) || compute(s, index+1, open, memo) ||
// 		compute(s, index+1, open+1, memo)
//
// 	memo[Pair{index, open}] = res
// 	return res
// }

func checkValidString(s string) bool {
	minOpen := 0
	maxOpen := 0

	for _, c := range s {
		if c == '(' {
			minOpen++
			maxOpen++
		} else if c == ')' {
			if maxOpen == 0 {
				return false
			}
			if minOpen != 0 {
				minOpen--
			}
			maxOpen--
		} else {
			maxOpen++
			if minOpen != 0 {
				minOpen--
			}
		}
	}

	return minOpen == 0
}
