package main

import "fmt"

//Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func main() {
	head := &ListNode{-1, nil}
	head.Val = -1
	tmp := head
	fmt.Println(tmp.Val)
	for i := 0; i < 5; i++ {
		newNode := &ListNode{0, nil}
		newNode.Val = i
		tmp.Next = newNode
		tmp = tmp.Next
	}

	head = reverseList(head)
	fmt.Println("!!!")
	for head != nil {
		fmt.Println(head.Val)
		head = head.Next
	}
}

func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return head
	}

	now := head
	next := head.Next
	//count := 1
	fmt.Println("place 1")
	for next != nil {
		//count++
		//fmt.Println(count)
		tmp := next.Next
		next.Next = now
		now = next
		next = tmp
	}
	fmt.Println("here")
	for now != nil {
		fmt.Println(now.Val)
		now = now.Next
	}
	return now
}
