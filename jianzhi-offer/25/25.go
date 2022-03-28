package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	var (
		head = &ListNode{}
		cur  = head
	)
	for l1 != nil || l2 != nil {
		if l1 == nil {
			cur.Next = l2
			break
		}

		if l2 == nil {
			cur.Next = l1
			break
		}

		if l1.Val < l2.Val {
			cur.Next = l1
			l1 = l1.Next
		} else {
			cur.Next = l2
			l2 = l2.Next
		}

		cur = cur.Next
	}

	return head.Next
}
