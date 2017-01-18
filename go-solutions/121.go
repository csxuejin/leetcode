func maxProfit(prices []int) int {
	if len(prices) <= 1 {
		return 0
	}
	min := 0
	for i := 0; i < len(prices)-1; i++ {
		for j := i + 1; j < len(prices); j++ {
			if (prices[j] - prices[i]) > min {
				min = prices[j] - prices[i]
			}
		}
	}
	return min
}