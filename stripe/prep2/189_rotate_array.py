from typing import List
from dataclasses import dataclass

# https://leetcode.com/problems/rotate-array/
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """


@dataclass
class TestSample:
    nums: List[int]
    k: int
    solution: List[int]

class TestRunner:
    data: List[TestSample]

    def __init__(self):
        self.data = [
            TestSample([1,2,3,4,5,6,7], 3, [5,6,7,1,2,3,4]),
            TestSample([-1,-100,3,99], 2, [3,99,-1,-100])
        ]

    def __check_result(self, sample: TestSample):
        if len(sample.nums) != len(sample.solution): 
            return False

        for i in range(len(sample.nums)):
            if sample.nums[i] != sample.solution[i]:
                return False

        return True

    def Run(self):
        print("Running tests...")
        s = Solution()
        for i, sample in enumerate(self.data):
            k = s.rotate(sample.nums, sample.k)
            print(f"Test {i}: {self.__check_result(sample)}")

if __name__ == "__main__":
    runner = TestRunner()
    runner.Run()