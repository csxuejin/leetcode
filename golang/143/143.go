package main

// https://leetcode-cn.com/problems/reorder-list/

type ListNode struct {
	Val  int
	Next *ListNode
}

func reorderList(head *ListNode) {
	cur := head
	arr := make([]*ListNode, 0)
	for cur != nil {
		arr = append(arr, cur)
		cur = cur.Next
	}

	var (
		i = 0
		j = len(arr) - 1
	)
	for i < j {
		arr[i].Next = arr[j]
		i++

		if i == j {
			break
		}
		arr[j].Next = arr[i]
		j--
	}
	arr[i].Next = nil // important

	return
}
