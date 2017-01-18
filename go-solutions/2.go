package main

//Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var newHead *ListNode
	tmp := newHead
	last := 0
	for {
		if l1 == nil && l2 == nil {
			break
		}
		val := last
		if l1 != nil {
			val += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			val += l2.Val
			l2 = l2.Next
		}
		tmp.Next = new * ListNode
		tmp.Next.Val = val % 10

		last = val / 10
		tmp = tmp.Next
	}
	if last != 0 {
		tmp.Next = new * ListNode
		tmp.Next.Val = last % 10
	}
	return newHead.Next
}
