from typing import List
from dataclasses import dataclass

# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return 0
@dataclass
class TestSample:
    prices: List[int]
    solution: int

class TestRunner:
    data: List[TestSample]

    def __init__(self):
        self.data = [
            TestSample([7,1,5,3,6,4], 5),
            TestSample([7,6,4,3,1], 0),
            TestSample([0,0,0,0], 0)
        ]

    def __check_result(self, sample: TestSample, k: int):
        return k == sample.solution

    def Run(self):
        print("Running tests...")
        s = Solution()
        for i, sample in enumerate(self.data):
            k = s.maxProfit(sample.prices)
            print(f"Test {i}: {self.__check_result(sample, k)}")

if __name__ == "__main__":
    runner = TestRunner()
    runner.Run()