package main

var strs []rune

func calculate(s string) int {
	strs = []rune(s)
	return helper()
}

func helper() int {
	stack := make([]int, 0)
	num := 0
	sign := '+'

	for len(strs) > 0 {
		v := strs[0]
		strs = strs[1:] // pop left

		if isDigit(v) {
			num = num*10 + int(v-'0')
		} else if v == '(' {
			num = helper()
		}

		if (!isDigit(v) && v != ' ') || len(strs) == 0 {
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

		if v == ')' {
			break
		}
	}

	res := 0
	for _, v := range stack {
		res += v
	}

	return res
}

func isDigit(s rune) bool {
	return s >= '0' && s <= '9'
}
