package main

import "fmt"

func countBinarySubstrings(s string) int {
	// get continue numbers
	cur := 1
	prev := 0
	for i := 1; i < len(s); i++ {
		if s[i-1] != s[i] {
			prev = cur
			cur = 1
		} else {
			cur++
		}
	}

	//
	return 0
}

func main() {
	fmt.Println(countBinarySubstrings("00110011"))
}
