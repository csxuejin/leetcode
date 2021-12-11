package main

import "container/heap"

type ListNode struct {
	Val  int
	Next *ListNode
}

type NodeHeap []*ListNode

func (h NodeHeap) Len() int {
	return len(h)
}

func (h NodeHeap) Less(i, j int) bool {
	return h[i].Val <= h[j].Val
}

func (h NodeHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *NodeHeap) Push(x interface{}) {
	*h = append(*h, x.(*ListNode))
}

func (h *NodeHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

/*
问题的关键在于要采用最小堆来存储数组元素，否则会超时
*/
func mergeKLists(lists []*ListNode) *ListNode {
	mergeHeap := &NodeHeap{}
	heap.Init(mergeHeap)

	for i := 0; i < len(lists); i++ {
		if lists[i] != nil {
			heap.Push(mergeHeap, lists[i])
		}
	}

	dummy := &ListNode{}
	p := dummy
	for mergeHeap.Len() > 0 {
		next := heap.Pop(mergeHeap).(*ListNode)
		if next.Next != nil {
			heap.Push(mergeHeap, next.Next)
		}
		p.Next = next
		p = p.Next
	}

	return dummy.Next
}
