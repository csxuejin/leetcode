package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func sortList(head *ListNode) *ListNode {
	return sort(head, nil)
}

func sort(head, tail *ListNode) *ListNode {
	if head == nil {
		return head
	}

	if head.Next == tail {
		head.Next = nil
		return head
	}

	slow, fast := head, head
	for fast != tail {
		slow = slow.Next
		fast = fast.Next
		if fast != tail {
			fast = fast.Next
		}
	}

	mid := slow
	return merge(sort(head, mid), sort(mid, tail))
}

func merge(head1, head2 *ListNode) *ListNode {
	dummy := &ListNode{}
	t, t1, t2 := dummy, head1, head2
	for t1 != nil && t2 != nil {
		if t1.Val < t2.Val {
			t.Next = t1
			t1 = t1.Next
		} else {
			t.Next = t2
			t2 = t2.Next
		}

		t = t.Next
	}

	if t1 == nil {
		t.Next = t2
	} else if t2 == nil {
		t.Next = t1
	}

	return dummy.Next
}
