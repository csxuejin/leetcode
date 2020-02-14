package main

func merge(nums1 []int, m int, nums2 []int, n int) {
	cur := m + n - 1
	i, j := m-1, n-1
	for i >= 0 || j >= 0 {
		switch {
		case i < 0:
			nums1[cur] = nums2[j]
			j--

		case j < 0:
			nums1[cur] = nums1[i]
			i--

		default:
			if nums1[i] > nums2[j] {
				nums1[cur] = nums1[i]
				i--
			} else {
				nums1[cur] = nums2[j]
				j--
			}
		}
		cur--
	}
}
