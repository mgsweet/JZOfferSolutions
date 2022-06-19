package main

func lengthOfLongestSubstring(s string) int {
	start, max := 0, 0
	var checked [256]int
	for i, c := range s {
		if checked[c] > start {
			start = checked[c]
		}

		if i-start+1 > max {
			max = i - start + 1
		}

		checked[c] = i + 1
	}

	return max
}

func main() {
	lengthOfLongestSubstring(" ")
}
