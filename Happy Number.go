package main

func isHappy(n int) bool {
	seen := make(map[int]bool)

	for n != 1 {
		if seen[n] {
			return false
		}
		seen[n] = true

		sum := 0
		for n != 0 {
			sum += (n % 10) * (n % 10)
			n = n / 10
		}
		n = sum
	}

	return true
}
