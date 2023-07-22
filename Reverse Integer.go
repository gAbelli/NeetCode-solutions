package main

import "math"

func reverse(x int) int {
	res := 0
	negative := x < 0

	if negative {
		x = -x
	}

	for x != 0 {
		if math.MaxInt32/10 < res {
			return 0
		}
		digit := x % 10
		x /= 10
		res *= 10
		res += digit
	}

	if negative {
		res = -res
	}
	return res
}
