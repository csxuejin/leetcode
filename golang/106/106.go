package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(inorder []int, postorder []int) *TreeNode {
	if len(inorder) == 0 {
		return nil
	}

	root := &TreeNode{
		Val: postorder[len(postorder)-1],
	}
	rootIndex := -1
	for i := 0; i < len(inorder); i++ {
		if inorder[i] == root.Val {
			rootIndex = i
			break
		}
	}

	root.Left = buildTree(inorder[0:rootIndex], postorder[0:rootIndex])
	root.Right = buildTree(inorder[rootIndex+1:], postorder[rootIndex:len(postorder)-1])
	return root
}
