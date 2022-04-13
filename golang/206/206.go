package main

type ListNode struct {
	Val  int
	Next *ListNode
}

// Solution 1: Iterative
func reverseList(head *ListNode) *ListNode {
	var prev *ListNode = nil
	for head != nil {
		nxt := head.Next
		head.Next = prev
		prev = head
		head = nxt
	}

	return prev
}

/* 也可能考察递归的写法
func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	last := reverseList(head.Next)
	head.Next.Next = head
	head.Next = nil
	return last
}
*/
