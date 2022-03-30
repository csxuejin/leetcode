package main

import "sort"

type ListNode struct {
	Val  int
	Next *ListNode
}

func sortList(head *ListNode) *ListNode {
	arrs := make([]int, 0)
	cur := head
	for cur != nil {
		arrs = append(arrs, cur.Val)
		cur = cur.Next
	}
	sort.Ints(arrs)

	h := &ListNode{}
	cur = h
	for _, v := range arrs {
		cur.Next = &ListNode{
			Val: v,
		}
		cur = cur.Next
	}
	return h.Next
}
