package main

import "strconv"

func numDecodings(s string) int {
	if len(s) < 1 || s[0] == '0' {
		return 0
	}

	dp := make([]int, len(s))
	dp[0] = 1
	for i := 1; i < len(s); i++ {
		str := string(s[i-1 : i+1])
		switch {
		case s[i] == '0':
			if equal(str, 10) || equal(str, 20) {
				if i < 2 {
					dp[i] = 1
				} else {
					dp[i] = dp[i-2]
				}
			} else {
				return 0
			}

		case between(str, 11, 26):
			if i > 2 {
				dp[i] = dp[i-1] + dp[i-2]
			} else {
				dp[i] = dp[i-1] + 1
			}

		default:
			dp[i] = dp[i-1]
		}
	}
	return dp[len(s)-1]
}

func equal(str string, num int) bool {
	return str == strconv.Itoa(num)
}

func between(str string, start, end int) bool {
	num, err := strconv.Atoi(str)
	if err != nil {
		return false
	}
	return num >= start && num <= end
}
