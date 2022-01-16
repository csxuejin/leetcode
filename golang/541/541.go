package main

func reverseStr(s string, k int) string {
	var res string
	if len(s) < 2*k && len(s) >= k {
		res = reverse(s[:k], k) + s[k:]
		return res
	}

	if len(s) >= 2*k {
		res = reverse(s[:2*k], k) + reverseStr(s[2*k:], k)
	}

	if len(s) < k {
		res = reverse(s, len(s))
	}
	return res
}

func reverse(s string, k int) string {
	runes := []rune(s)
	for i, j := 0, k-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}
