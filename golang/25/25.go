package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil {
		return nil
	}

	a := head
	b := head
	for i := 0; i < k; i++ {
		if b == nil {
			return head
		}
		b = b.Next
	}

	newHead := reverse(a, b)
	a.Next = reverseKGroup(b, k)
	return newHead
}

func reverse(a, b *ListNode) *ListNode {
	var (
		pre  *ListNode
		cur  = a
		next = a
	)
	for cur != b {
		next = cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}
	return pre
}
