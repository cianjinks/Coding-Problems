from typing import List
from dataclasses import dataclass

# https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if (len(nums) == 1): return 1

        index = 1
        for i in range(1, len(nums)):
            if (nums[index - 1] != nums[i]):
                nums[index] = nums[i]
                index += 1
        return index

# [0,0,1,1,1,2,2,3,3,4]

@dataclass
class TestSample:
    nums: List[int]
    expectedNums: List[int]

class TestRunner:
    data: List[TestSample]

    def __init__(self):
        self.data = [
            TestSample([1, 1, 2], [1, 2]),
            TestSample([0,1,1,1,2,2,3,3,4], [0,1,2,3,4])
        ]

    def __check_result(self, sample: TestSample, k: int):
        if (k != len(sample.expectedNums)):
            return False

        for i in range(k):
            if (sample.nums[i] != sample.expectedNums[i]):
                return False

        return True

    def Run(self):
        print("Running tests...")
        s = Solution()
        for i, sample in enumerate(self.data):
            k = s.removeDuplicates(sample.nums)
            print(f"Test {i}: {self.__check_result(sample, k)}")

if __name__ == "__main__":
    runner = TestRunner()
    runner.Run()