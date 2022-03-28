package main

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	var (
		odd        bool
		count, mid int
		res        float64
		len1       = len(nums1)
		len2       = len(nums2)
	)

	if (len1+len2)%2 != 0 {
		odd = true
		mid = (len1+len2)/2 + 1
	} else {
		mid = (len1 + len2) / 2
	}

	for i, j := 0, 0; i < len1 || j < len2; {
		t := 0
		if j >= len2 || (i < len1 && j < len2 && nums1[i] <= nums2[j]) {
			t = nums1[i]
			i++
		} else if i >= len1 || (i < len1 && j < len2 && nums1[i] > nums2[j]) {
			t = nums2[j]
			j++
		}

		count++
		switch count {
		case mid:
			res += float64(t)
			if odd {
				return res
			}
		case mid + 1:
			res += float64(t)
			return res / 2
		}
	}

	return res
}
