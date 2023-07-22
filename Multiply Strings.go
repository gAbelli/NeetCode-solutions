package main

import (
	"fmt"
	"math"
)

func sum(num1 string, num2 string) string {
	res := ""
	remainder := 0
	for i := 0; i < len(num1) || i < len(num2); i++ {
		cur := remainder
		if i < len(num1) {
			cur += int(num1[len(num1)-1-i] - '0')
		}
		if i < len(num2) {
			cur += int(num2[len(num2)-1-i] - '0')
		}
		remainder = cur / 10
		cur = cur % 10
		res = fmt.Sprint(cur) + res
	}
	if remainder != 0 {
		res = fmt.Sprint(remainder) + res
	}

	return res
}

func multiply(num1 string, num2 string) string {
	current := "0"
	tot := "0"
	remainder := byte(0)

	for j := len(num2) - 1; j >= 0; j-- {
		for i := len(num1) - 1; i >= 0; i-- {
			mul := (num2[j]-'0')*(num1[i]-'0') + remainder
			remainder = 0
			remainder = mul / 10
			mul = mul % 10
			current = sum(current, fmt.Sprint(int(mul)*int(math.Pow(10, float64(len(num1)-1-i)))))
		}
		current = sum(current, fmt.Sprint(int(remainder)*int(math.Pow(10, float64(len(num1))))))
		remainder = 0
		for k := 0; k < len(num2)-1-j; k++ {
			current = current + "0"
		}

		tot = sum(tot, current)
		current = "0"
	}

	firstNonZero := 0
	for i, c := range tot {
		if c != '0' {
			firstNonZero = i
			break
		}
	}
	res := tot[firstNonZero:]
	if len(res) == 0 {
		res = "0"
	}

	return res
}
