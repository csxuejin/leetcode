package main

func calculate(s string) int {
	stack := make([]int, 0)
	num := 0
	sign := '+'

	for i, v := range s {
		if isDigit(v) {
			num = num*10 + int(v-'0')
		}

		if (!isDigit(v) && v != ' ') || i == len(s)-1 {
			switch sign {
			case '+':
				stack = append(stack, num)

			case '-':
				stack = append(stack, -1*num)

			case '*':
				pre := stack[len(stack)-1]
				stack = stack[:len(stack)-1]
				stack = append(stack, pre*num)

			case '/':
				pre := stack[len(stack)-1]
				stack = stack[:len(stack)-1]
				stack = append(stack, pre/num)
			}

			sign = v
			num = 0
		}
	}

	res := 0
	for len(stack) > 0 {
		res = res + stack[len(stack)-1]
		stack = stack[:len(stack)-1]
	}

	return res
}

func isDigit(s rune) bool {
	return s >= '0' && s <= '9'
}
