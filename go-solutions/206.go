/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

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

// Solution 2: Recursive
func reverseList_recursively(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	p := reverseList(head.Next)

	head.Next.Next = head
	head.Next = nil
	return p
}
