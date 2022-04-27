package main

// 2 的幂数转为二进制后只有一位是 1
func isPowerOfTwo(n int) bool {
	if n == 0 {
		return false
	}
	return n&(n-1) == 0
}
