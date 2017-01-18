func helper(a, b string) bool {
	return (a+b == "()") || (a+b == "[]") || (a+b == "{}")
}

func isValid(s string) bool {
	str := ""
	for _, t := range s {
		v := string(t)
		if v == "(" || v == "[" || v == "{" {
			str += v
		} else {
			if len(str) == 0 {
				return false
			}
			if !helper(string(str[len(str)-1]), string(v)) {
				return false
			}
			str = str[:len(str)-1]
		}
	}
	return len(str) == 0
}