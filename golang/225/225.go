package main

type MyStack struct {
	q1, q2 []int
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{
		q1: make([]int, 0),
		q2: make([]int, 0),
	}
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int) {
	this.q1 = append(this.q1, x)
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	length := len(this.q1)
	for i := 0; i < length-1; i++ {
		this.q2 = append(this.q2, this.q1[0])
		this.q1 = this.q1[1:]
	}
	topEle := this.q1[0]
	this.q1 = this.q2
	this.q2 = nil
	return topEle
}

/** Get the top element. */
func (this *MyStack) Top() int {
	topEle := this.Pop()
	this.q1 = append(this.q1, topEle)
	return topEle
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return len(this.q1) == 0
}

/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */

// method 2: use container/list to mock queue
//import "container/list"
//
//type MyStack struct {
//	q1 *list.List
//	q2 *list.List
//}
//
///** Initialize your data structure here. */
//func Constructor() MyStack {
//	return MyStack{
//		q1: list.New(),
//		q2: list.New(),
//	}
//}
//
///** Push element x onto stack. */
//func (this *MyStack) Push(x int)  {
//	this.q1.PushBack(x)
//}
//
///** Removes the element on top of the stack and returns that element. */
//func (this *MyStack) Pop() int {
//	for this.q1.Len() > 1 {
//		ele := this.q1.Front()
//		fmt.Printf("ele value is %v\n", ele.Value)
//		this.q2.PushBack(ele.Value)
//		this.q1.Remove(ele)
//	}
//	res := this.q1.Front()
//	this.q1.Remove(res)
//
//	this.q1 = this.q2
//	this.q2 = list.New()
//
//	return res.Value.(int)
//}
//
///** Get the top element. */
//func (this *MyStack) Top() int {
//	ele := this.Pop()
//	this.q1.PushBack(ele)
//	return ele
//}
//
///** Returns whether the stack is empty. */
//func (this *MyStack) Empty() bool {
//	return this.q1.Len() == 0
//}
