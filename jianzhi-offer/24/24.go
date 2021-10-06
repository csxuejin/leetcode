package main

// https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/

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

