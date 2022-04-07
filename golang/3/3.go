package main

// 滑动窗口问题
func lengthOfLongestSubstring(s string) int {
	cnt := make(map[rune]int)

	left, right := 0, 0
	res := 0

	ss := []rune(s)
	for _, v := range ss {
		cnt[v]++

		for cnt[v] > 1 {
			// shrink
			cnt[ss[left]]--
			left++
		}

		res = max(res, (right-left)+1)
		right++
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
