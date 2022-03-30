package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	plus := 0
	head := &ListNode{}
	ptr := head

	for l1 != nil || l2 != nil {
		sum := plus

		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}

		ptr.Next = &ListNode{
			Val: sum % 10,
		}

		ptr = ptr.Next
		plus = sum / 10
	}

	if plus != 0 {
		ptr.Next = &ListNode{
			Val: plus,
		}
	}

	return head.Next
}
