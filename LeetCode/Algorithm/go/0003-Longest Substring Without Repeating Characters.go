func lengthOfLongestSubstring(s string) int {
	var checked [256]int
	start := 0
	res := 0
	for i, c := range s {
		if checked[c] > start {
			start = checked[c]
		}
		if res < i-start+1 {
			res = i - start + 1
		}
		checked[c] = i + 1
	}
	return res
}