package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func reversePrint(head *ListNode) []int {
	arr := make([]int, 0)
	for head != nil {
		arr = append(arr, head.Val)
		head = head.Next
	}

	res := make([]int, len(arr))
	i := 0
	j := len(arr) - 1
	for j >= 0 {
		res[i] = arr[j]
		j--
		i++
	}
	return res
}
