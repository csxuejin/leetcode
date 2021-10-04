func isHappy(n int) bool {
	mm := make(map[int]int)
	if n == 1 {
		return true
	}
	for n != 1 {
		n = getSquare(n)
		if _, ok := mm[n]; ok {
			return false
		}
		mm[n]++
	}
	return true
}

func getSquare(n int) int {
	sum := 0
	for n != 0 {
		tmp := n % 10
		sum += tmp * tmp
		n /= 10
	}
	return sum
}


