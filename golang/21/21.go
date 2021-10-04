package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	cur := &ListNode{}
	head := cur

	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			cur.Next = l1
			l1 = l1.Next
		} else {
			cur.Next = l2
			l2 = l2.Next
		}
		cur = cur.Next
	}

	if l1 == nil {
		cur.Next = l2
	} else {
		cur.Next = l1
	}
	return head.Next
}

// method 2: use recursion
//func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
//	if l1 == nil {
//		return l2
//	}
//
//	if l2 == nil {
//		return l1
//	}
//
//	if l1.Val < l2.Val {
//		l1.Next = mergeTwoLists(l1.Next, l2)
//		return l1
//	}
//
//	l2.Next = mergeTwoLists(l1, l2.Next)
//	return l2
//}
