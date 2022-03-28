package main

func hammingDistance(x int, y int) int {
	s := x ^ y
	res := 0
	for s != 0 {
		s &= s - 1
		res++
	}
	return res
}
