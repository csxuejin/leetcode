package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func constructMaximumBinaryTree(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	max := -1
	index := 0

	for i := 0; i < len(nums); i++ {
		if nums[i] > max {
			max = nums[i]
			index = i
		}
	}

	root := &TreeNode{
		Val: nums[index],
	}
	if index-1 >= 0 {
		root.Left = constructMaximumBinaryTree(nums[0:index])
	}

	if index+1 < len(nums) {
		root.Right = constructMaximumBinaryTree(nums[index+1:])
	}
	return root
}
