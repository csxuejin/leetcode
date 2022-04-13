package main

type Node struct {
	Val   int
	Left  *Node
	Right *Node
	Next  *Node
}

func connect(root *Node) *Node {
	if root == nil {
		return root
	}

	queue := []*Node{root}

	for len(queue) > 0 {
		tmp := queue
		queue = make([]*Node, 0)

		for i, v := range tmp {
			if i+1 < len(tmp) {
				v.Next = tmp[i+1]
			}

			if v.Left != nil {
				queue = append(queue, v.Left)
			}

			if v.Right != nil {
				queue = append(queue, v.Right)
			}
		}
	}

	return root
}

/*
func connect(root *Node) *Node {
	if root == nil {
		return root
	}
	connTwoNode(root.Left, root.Right)
	return root
}

func connTwoNode(n1, n2 *Node) {
	if n1 == nil || n2 == nil {
		return
	}
	n1.Next = n2

	connTwoNode(n1.Left, n1.Right)
	connTwoNode(n2.Left, n2.Right)
	connTwoNode(n1.Right, n2.Left)
}
*/
