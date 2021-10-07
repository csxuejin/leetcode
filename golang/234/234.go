package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func isPalindrome(head *ListNode) bool {
	arr := make([]int, 0)
	for head != nil {
		arr = append(arr, head.Val)
		head = head.Next
	}

	i := 0
	j := len(arr) - 1
	for i < j {
		if arr[i] != arr[j] {
			return false
		}
		i++
		j--
	}
	return true
}
