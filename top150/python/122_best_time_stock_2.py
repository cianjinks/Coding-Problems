from typing import List
import unittest

# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
# class Solution:
#     def maxProfit(self, prices: List[int]) -> int:
#         bought = False
#         c = prices[0]
#         max_profit = 0

#         for i in range(len(prices) - 1):
#             if prices[i] <= prices[i + 1]:
#                 if not bought:
#                     # If it starts to go up we want to buy
#                     c = prices[i]
#                     bought = True
#             else:
#                 if bought:
#                     # If it starts to go down we want to sell
#                     max_profit += prices[i] - c
#                     bought = False

#         if bought:
#              max_profit += prices[-1] - c

#         return max_profit

# Better solution, just buying and selling immediately whenever profit goes up!
# In both solutions we are summing upward slopes in the graph
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        for i in range(1, len(prices)):
            if (prices[i] > prices[i - 1]):
                max_profit += prices[i] - prices[i - 1]
        return max_profit

class Test(unittest.TestCase):
    def test(self):
        s = Solution()
        self.assertEqual(s.maxProfit([7,1,5,3,6,4]), 7)
        self.assertEqual(s.maxProfit([1,2,3,4,5]), 4)
        self.assertEqual(s.maxProfit([7,6,4,3,1]), 0)

if __name__ == "__main__":
    unittest.main()