package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	exist := make(map[*ListNode]bool)

	for headA != nil || headB != nil {
		if headA != nil {
			if exist[headA] {
				return headA
			}
			exist[headA] = true
			headA = headA.Next
		}

		if headB != nil {
			if exist[headB] {
				return headB
			}
			exist[headB] = true
			headB = headB.Next
		}
	}
	return nil
}
