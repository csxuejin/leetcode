package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func bfs(root *TreeNode, level int, sum *[][]int) {
	if len(*sum) <= level {
		(*sum) = append((*sum), []int{})
	}
	(*sum)[level] = append((*sum)[level], root.Val)
	if root.Left != nil {
		bfs(root.Left, level+1, sum)
	}
	if root.Right != nil {
		bfs(root.Right, level+1, sum)
	}
}

func levelOrderBottom(root *TreeNode) [][]int {
	sum := [][]int{}
	if root == nil {
		return sum
	}
	bfs(root, 0, &sum)
	for i, j := 0, len(sum)-1; i < j; i, j = i+1, j-1 {
		sum[i], sum[j] = sum[j], sum[i]
	}
	return sum
}
