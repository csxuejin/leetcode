package main

type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

var cache map[*Node]*Node

func copyRandomList(head *Node) *Node {
	cache = make(map[*Node]*Node)
	return copy(head)
}

func copy(head *Node) *Node {
	if head == nil {
		return nil
	}

	if n, ok := cache[head]; ok {
		return n
	}

	node := &Node{
		Val: head.Val,
	}

	cache[head] = node
	node.Next = copy(head.Next)
	node.Random = copy(head.Random)
	return node
}
