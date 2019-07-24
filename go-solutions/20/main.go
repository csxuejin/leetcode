package main

func main() {

}

func isValid(s string) bool {
	stack := newStack()
	for _, v := range s {
		str := string(v)
		if isLeft(str) {
			stack.push(str)
			continue
		}

		if !isMatch(stack.pop(), str) {
			return false
		}
	}

	return stack.isEmpty()
}

func isLeft(str string) bool {
	return str == "(" || str == "{" || str == "["
}

func isMatch(left, right string) bool {
	str := left + right
	return str == "()" || str == "[]" || str == "{}"
}

type stack struct {
	content []string
}

func newStack() *stack {
	return &stack{
		content: make([]string, 0),
	}
}

func (s *stack) isEmpty() bool {
	return len(s.content) == 0
}

func (s *stack) pop() string {
	length := len(s.content)
	if length == 0 {
		return ""
	}

	res := s.content[length-1]
	s.content = s.content[:length-1]
	return res
}

func (s *stack) push(str string) {
	s.content = append(s.content, str)
}
