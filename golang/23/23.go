package main

// 方法一：归并排序
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeKLists(lists []*ListNode) *ListNode {
	return sort(lists, 0, len(lists)-1)
}

func sort(lists []*ListNode, l, r int) *ListNode {
	if l == r {
		return lists[l]
	}

	if l > r {
		return nil
	}

	mid := (l + r) / 2
	return merge(sort(lists, l, mid), sort(lists, mid+1, r))
}

func merge(h1, h2 *ListNode) *ListNode {
	dummy := &ListNode{}
	t, t1, t2 := dummy, h1, h2
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

/* 方法二：最小堆

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

// 问题的关键在于要采用最小堆来存储数组元素，否则会超时
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
*/
