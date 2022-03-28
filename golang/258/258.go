package main

func addDigits(num int) int {
	for num >= 10 {
		tmp := num
		num = 0
		for tmp != 0 {
			num += tmp % 10
			tmp /= 10
		}
	}
	return num
}
