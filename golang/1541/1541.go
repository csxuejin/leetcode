package main

func minInsertions(s string) int {
	insert := 0    // 插入的左右括号之和
	needRight := 0 // 当前需要的右括号数

	for _, v := range s {
		switch v {
		case '(':
			needRight += 2
			if needRight%2 == 1 {
				insert++
				needRight--
			}

		case ')':
			needRight--
			if needRight == -1 {
				insert++
				needRight = 1
			}
		}
	}

	return insert + needRight
}
