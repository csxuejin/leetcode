package main

func findAnagrams(s string, p string) []int {
	need := make(map[byte]int)
	for _, v := range []byte(p) {
		need[v]++
	}

	left, right := 0, 0
	valid := 0
	window := make(map[byte]int)
	result := make([]int, 0)
	for ; right < len(s); right++ {
		c := s[right]
		window[c]++

		if window[c] == need[c] {
			valid++
		}

		for right-left+1 >= len(p) {
			if valid == len(need) {
				result = append(result, left)
			}

			lVal := s[left]
			if window[lVal] == need[lVal] {
				valid--
			}
			window[lVal]--
			left++
		}
	}
	return result
}
