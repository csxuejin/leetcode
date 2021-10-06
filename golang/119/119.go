package main

func getRow(rowIndex int) []int {
	trian := [][]int{}
	trian = append(trian, []int{1})
	if rowIndex == 0 {
		return trian[0]
	}
	for i := 1; i <= rowIndex; i++ {
		tmp := []int{1}
		for j := 1; j <= i-1; j++ {
			tmp = append(tmp, trian[i-1][j-1]+trian[i-1][j])
		}
		tmp = append(tmp, 1)
		trian = append(trian, tmp)
	}
	return trian[rowIndex]
}
