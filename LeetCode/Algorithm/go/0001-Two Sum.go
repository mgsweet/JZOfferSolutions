package main

func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for i, v := range nums {
		if preI, ok := m[target-v]; ok {
			return []int{preI, i}
		}
		m[v] = i
	}
	return []int{-1, -1}
}
