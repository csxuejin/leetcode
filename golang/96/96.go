package main

var memo [][]int

func numTrees(n int) int {
	memo = make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		memo[i] = make([]int, n+1)
	}
	return count(1, n)
}

func count(lo, hi int) int {
	if lo > hi {
		return 1
	}

	if memo[lo][hi] != 0 {
		return memo[lo][hi]
	}

	res := 0
	for mid := lo; mid <= hi; mid++ {
		res += count(lo, mid-1) * count(mid+1, hi)
	}
	memo[lo][hi] = res

	return res
}
