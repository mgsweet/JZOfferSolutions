func reverse(x int) int {
	res := 0
	for x != 0 {
		res = res*10 + x%10
		if res > 2147483647 || res < -2147483648 {
			return 0
		}
		x /= 10
	}
	return res
}