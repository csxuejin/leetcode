package main

func twoSum(nums []int, target int) []int {
	mm := make(map[int]int)
	for i, v := range nums {
		rest, ok := mm[target-v]
		if ok {
			return []int{rest, i}
		}
		mm[v] = i
	}
	return nil
}

// method 2: sort struct slice
//type Node struct{
//	index, val int
//}
//
//func twoSum(nums []int, target int) []int {
//	var nodes []Node
//	for i, v := range nums{
//		nodes = append(nodes, Node{
//			index: i,
//			val: v,
//		})
//	}
//	sort.Slice(nodes, func(i, j int) bool {
//		return nodes[i].val< nodes[j].val
//	})
//
//	left, right := 0, len(nums) - 1
//	for left < right {
//		val := nodes[left].val + nodes[right].val
//		switch {
//		case val == target:
//			return []int{nodes[left].index, nodes[right].index}
//
//		case val < target:
//			left++
//
//		default:
//			right--
//		}
//	}
//	return nil
//}
