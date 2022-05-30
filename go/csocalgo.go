package main

import (
	"fmt"
)

func sizeLIS(arr []int) int {

	length := len(arr)
	lis := make([]int, length)

	for i := 0; i < length; i++ {
		lis[i] = 1
	}

	for i := 1; i < length; i++ {
		for j := 0; j < i; j++ {
			if arr[i] > arr[j] && lis[i] < (lis[j]+1) {
				lis[i] = lis[j] + 1
			}
		}
	}

	max := 0

	for i := 0; i < length; i++ {
		if lis[i] > max {
			max = lis[i]
		}
	}

	return max
}

func main() {
	output := sizeLIS([]int{1, 2, 3, 0})
	fmt.Println(output)
}
