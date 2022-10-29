package main

import "fmt"

func minFlipsMonoIncr(s string) int {
	// there are two case
	// if there're few 1
	// numberofone = count the number of 1

	var numberofone int = 0
	var numberofzero int = 0
	var firstoneposition int = 0
	var firstfound bool = false
	for position, char := range s {
		if char == '1' {
			numberofone++
			if firstfound == false {
				firstoneposition = position
				firstfound = true
			}
		}

		if char == '0' {
			if firstfound == true {
				numberofzero++
			}
		}

		_ = firstoneposition

	}

	return 0
}

func main() {
	var input string
	fmt.Scanf("%s", &input)
	fmt.Print(minFlipsMonoIncr(input))
}
