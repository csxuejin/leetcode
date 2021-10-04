package main

func largestRectangleArea(heights []int) int {
	stack := NewMyStack()
	stack.push(-1)

	maxArea := 0
	for i := 0; i < len(heights); i++ {
		for stack.peek() != -1 && heights[stack.peek()] >= heights[i] {
			maxArea = max(maxArea, heights[stack.pop()]*(i-stack.peek()-1))
		}
		stack.push(i)
	}
	for stack.peek() != -1 {
		maxArea = max(maxArea, heights[stack.pop()]*(len(heights)-stack.peek()-1))
	}
	return maxArea
}

type MyStack struct {
	data []int
}

func NewMyStack() *MyStack {
	return &MyStack{
		data: make([]int, 0),
	}
}

func (s *MyStack) push(x int) {
	s.data = append(s.data, x)
}

func (s *MyStack) pop() int {
	if len(s.data) < 1 {
		return -1
	}
	ele := s.data[len(s.data)-1]
	s.data = s.data[:len(s.data)-1]
	return ele
}

func (s *MyStack) peek() int {
	if len(s.data) < 1 {
		return -1
	}

	return s.data[len(s.data)-1]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
