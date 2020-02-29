package main

func canJump(nums []int) bool {
	lastPos := len(nums) - 1
	for i := len(nums) - 1; i >= 0; i-- {
		if i+nums[i] >= lastPos {
			lastPos = i
		}
	}
	return lastPos == 0
}

// method 2
// func canJump(nums []int) bool {
//     maxReach := 1
//     for i:=0; i<len(nums); i++ {
//         maxReach--
//         if maxReach < 0 {
//            return false
//         }
//         maxReach = max(maxReach, nums[i])
//         if maxReach >= len(nums)-i {
//            return true
//         }
//     }
//     return maxReach >= 0
// }

// func max(a, b int) int {
//     if a > b {
//         return a
//     }
//     return b
// }
