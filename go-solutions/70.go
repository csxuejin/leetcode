package main

func climbStairs(n int) int {
	switch {
	case n == 1:
		return 1

	case n == 2:
		return 2

	default:
		nums := make([]int, n+1)
		nums[1] = 1
		nums[2] = 2
		for i := 3; i <= n; i++ {
			nums[i] = nums[i-1] + nums[i-2]
		}
		return nums[n]
	}
}

//var mm = make(map[int]int)
//
//func climbStairs(n int) int {
//	switch n {
//	case 1:
//		return 1
//
//	case 2:
//		return 2
//
//	default:
//		if _, ok := mm[n-1]; !ok {
//			mm[n-1] = climbStairs(n - 1)
//		}
//
//		if _, ok := mm[n-2]; !ok {
//			mm[n-2] = climbStairs(n - 2)
//		}
//
//		return mm[n-1] + mm[n-2]
//	}
//}
