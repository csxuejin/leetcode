package main

type ListNode struct {
	Val  int
	Next *ListNode
}

/*
双指针解法：
- p1 遍历的是 链表A + 链表B
- p2 遍历的是 链表B + 链表A
*/
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	p1 := headA
	p2 := headB
	for p1 != p2 {
		if p1 != nil {
			p1 = p1.Next
		} else {
			p1 = headB
		}

		if p2 != nil {
			p2 = p2.Next
		} else {
			p2 = headA
		}
	}

	return p1
}

/*
   较差的做法就是用 map 标记已经走过的节点, 如下：

   func getIntersectionNode(headA, headB *ListNode) *ListNode {
   	exist := make(map[*ListNode]bool)

   	for headA != nil || headB != nil {
   		if headA != nil {
   			if exist[headA] {
   				return headA
   			}
   			exist[headA] = true
   			headA = headA.Next
   		}

   		if headB != nil {
   			if exist[headB] {
   				return headB
   			}
   			exist[headB] = true
   			headB = headB.Next
   		}
   	}
   	return nil
   }
*/
