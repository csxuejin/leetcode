package main

func main(){

}

func findKthLargest(nums []int, k int) int {
	sortElements(nums)

	return nums[len(nums)-k]
}

func sortElements(s []int){
	quickSort(s, 0, len(s) - 1)
}

func quickSort(s []int, start, end int){
	if start >= end{
		return
	}

	split := partition(s , start, end)
	quickSort(s, start, split-1)
	quickSort(s, split+1, end)
}

func partition(s []int, start, end int) int{
	pivort := s[end]

	i := start
	for j:=start; j<end; j++{
		if s[j] < pivort{
			s[i], s[j] = s[j], s[i]
			i++
		}
	}

	s[i], s[end] = s[end], s[i]
	return i
}
