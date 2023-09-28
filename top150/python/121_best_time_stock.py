from typing import List
import unittest

# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        c = prices[0]
        max_profit = 0
        for price in prices:
            if price < c:
                c = price
            elif (price - c) > max_profit:
                max_profit = price - c
        return max_profit

class Test(unittest.TestCase):
    def test(self):
        s = Solution()
        self.assertEqual(s.maxProfit([7,1,5,3,6,4]), 5)
        self.assertEqual(s.maxProfit([7,6,4,3,1]), 0)

if __name__ == "__main__":
    unittest.main()