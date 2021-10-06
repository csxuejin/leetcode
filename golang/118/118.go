package main

func generate(numRows int) [][]int {
	trian := [][]int{}
	if numRows == 0 {
		return trian
	}
	trian = append(trian, []int{1})
	for i := 1; i < numRows; i++ {
		tmp := []int{1}
		for j := 1; j < i; j++ {
			tmp = append(tmp, trian[i-1][j-1]+trian[i-1][j])
		}
		tmp = append(tmp, 1)
		trian = append(trian, tmp)
	}
	return trian
}
