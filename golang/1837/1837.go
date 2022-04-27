package main

func sumBase(n int, k int) int {
	r := convert(n, k)
	return cnt(r)
}

func convert(n, k int) int {
	res := 0
	for n != 0 {
		v := n % k
		res = res*10 + v
		n = n / k
	}
	return res
}

func cnt(n int) int {
	res := 0
	for n != 0 {
		res = res + n%10
		n = n / 10
	}

	return res
}
