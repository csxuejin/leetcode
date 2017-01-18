package main

import "fmt"

func main() {
	// nums1 := []int{1, 3, 5, 7}
	nums1 := make([]int, 1, 2)
	nums1 = []int{0}
	// nums2 := []int{2, 4, 6, 8}
	nums2 := []int{1}
	merge(nums1, 0, nums2, 1)
}

func merge(nums1 []int, m int, nums2 []int, n int) {
	nums := []int{}
	i, j := 0, 0
	for i < m && j < n {
		if nums1[i] < nums2[j] {
			nums = append(nums, nums1[i])
			i++
		} else {
			nums = append(nums, nums2[j])
			j++
		}
	}

	for i < m {
		nums = append(nums, nums1[i])
		i++
	}
	for j < n {
		nums = append(nums, nums2[j])
		j++
	}
	nums1 = nums
	fmt.Println(nums1)
}
