package main

func plusOne(digits []int) []int {
	n := len(digits)
	remainder := true

	for i := n - 1; i >= 0; i-- {
		if remainder {
			digits[i] += 1
		}
		remainder = false
		if digits[i] > 9 {
			remainder = true
			digits[i] -= 10
		}
	}

	res := digits

	if remainder {
		res = []int{1}
		res = append(res, digits...)
	}

	return res
}
