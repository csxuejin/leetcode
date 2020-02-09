package main

var mm = make(map[int]int)

func climbStairs(n int) int {
	switch n {
	case 1:
		return 1

	case 2:
		return 2

	default:
		if _, ok := mm[n-1]; !ok {
			mm[n-1] = climbStairs(n - 1)
		}

		if _, ok := mm[n-2]; !ok {
			mm[n-2] = climbStairs(n - 2)
		}

		return mm[n-1] + mm[n-2]
	}
}
