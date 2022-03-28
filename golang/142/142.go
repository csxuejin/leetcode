package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func detectCycle(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return nil
	}

	var cycleExist bool
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if slow == fast {
			cycleExist = true
			break
		}
	}

	if !cycleExist {
		return nil
	}

	fast = head
	for slow != nil && slow != fast {
		slow = slow.Next
		fast = fast.Next
	}
	return fast
}
