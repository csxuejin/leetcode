package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil {
		return head
	}

	start, end := head, head
	for i := 0; i < k; i++ {
		if end == nil {
			return head
		}
		end = end.Next
	}

	newHead := reverse(start, end)
	start.Next = reverseKGroup(end, k)
	return newHead
}

func reverse(start, end *ListNode) *ListNode {
	var prev *ListNode
	cur := start

	for cur != end {
		nxt := cur.Next
		cur.Next = prev
		prev = cur
		cur = nxt
	}

	return prev
}
