/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}

	prv := &ListNode{
		Val:  head.Val,
		Next: nil,
	}

	head = head.Next
	for head != nil {
		tmp := &ListNode{
			Val:  head.Val,
			Next: prv,
		}

		prv = tmp
		head = head.Next
	}

	return prv
}
