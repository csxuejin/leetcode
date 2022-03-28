package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func pathSum(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}

	res := 0
	helper(root, 0, &sum, &res)

	return res + pathSum(root.Left, sum) + pathSum(root.Right, sum)
}

func helper(root *TreeNode, currentSum int, sum, res *int) {
	if root == nil {
		return
	}

	currentSum += root.Val
	if currentSum == *sum {
		*res += 1
	}

	helper(root.Left, currentSum, sum, res)
	helper(root.Right, currentSum, sum, res)
}
