package main

import (
	"fmt"
)

type stack []rune

func (s stack) Push(v rune) stack {
	return append(s, v)
}

func (s stack) Pop() (stack, rune) {
	// FIXME: What do we do if the stack is empty, though?

	l := len(s)
	return s[:l-1], s[l-1]
}

func main() {
	// open braces
	// ([{
	// close braces }])

	var input string
	fmt.Scanf("%s", &input)

	s := make(stack, 0)

	for _, char := range input {
		if char == '(' || char == '[' || char == '{' {
			s = s.Push(char)
			continue
		}
		if char == ')' {
			s, p := s.Pop()
			if p == '(' {
				fmt.Printf("Matched")
			} else {
				fmt.Printf("Fail")
			}
			continue
		}
		if char == ']' {
			s, p := s.Pop()
			if p == '[' {
				fmt.Printf("Matched")
			} else {
				fmt.Printf("Fail")
			}
			continue
		}

		if char == '}' {
			s, p := s.Pop()
			if p == '{' {
				fmt.Printf("Matched")
			} else {
				fmt.Printf("Fail")
			}
			continue
		}
	}
	// golang sort
}
