package main

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{}
	start := head
	last := 0
	for l1 != nil || l2 != nil {
		val := last
		if l1 != nil {
			val += l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			val += l2.Val
			l2 = l2.Next
		}

		start.Next = &ListNode{
			Val: val % 10,
		}
		last = val / 10
		start = start.Next
	}

	if last != 0 {
		start.Next = &ListNode{
			Val: last,
		}
	}

	return head.Next
}
