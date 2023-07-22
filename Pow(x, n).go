package main

func myPow(x float64, n int) float64 {
	if n == 0 {
		return 1
	}
	if n < 0 {
		x = 1 / x
		n = -n
	}

	m := uint32(n)

	res := 1.0
	cur := x
	for m != 0 {
		if m&0x1 != 0 {
			res *= cur
		}
		cur *= cur
		m = m >> 1
	}

	return res
}

// n = a_k     * 2^k     +
//     a_{k-1} * 2^{k-1} +
//     a_{k-2} * 2^{k-2} +
// ...
//     a_0     * 2^0

// x^n = x^{a_k * 2^k} * x^{a_{k-1} * 2^{k-1}} * ...
