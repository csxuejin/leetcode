package main

func lemonadeChange(bills []int) bool {
	money := make(map[int]int)
	for _, v := range bills {
		switch v {
		case 5:
			money[5]++

		case 10:
			if money[5] > 0 {
				money[5]--
				money[10]++
			} else {
				return false
			}

		case 20:
			if money[10] > 0 && money[5] > 0 {
				money[10]--
				money[5]--
			} else if money[5] >= 3 {
				money[5] -= 3
			} else {
				return false
			}
		}
	}
	return true
}
