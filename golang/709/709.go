package main

func toLowerCase(s string) string {
	res := make([]rune, len(s))
	for i, v := range s {
		if v >= 'A' && v <= 'Z' {
			v = v + 32
		}
		res[i] = v
	}
	return string(res)
}
