package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var (
		current, next int
		head          = &ListNode{}
		ptr           = head
	)

	for l1 != nil || l2 != nil {
		current = next

		if l1 != nil {
			current += l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			current += l2.Val
			l2 = l2.Next
		}

		next = current / 10
		current = current % 10

		ptr.Next = &ListNode{
			Val: current,
		}

		ptr = ptr.Next
	}

	if next != 0 {
		ptr.Next = &ListNode{
			Val: next,
		}
	}

	return head.Next
}
