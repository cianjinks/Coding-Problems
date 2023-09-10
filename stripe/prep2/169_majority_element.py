from typing import List
from dataclasses import dataclass

# https://leetcode.com/problems/majority-element/
# Should be possible in linear time with O(1) space
# For now will do without
# class Solution:
#     def majorityElement(self, nums: List[int]) -> int:
#         buckets = {}
#         for num in nums:
#             if num in buckets:
#                 buckets[num] += 1
#             else:
#                 buckets[num] = 1

#         majority_elem = next(iter(buckets.keys()))
#         majority = next(iter(buckets.values()))
#         for k, v in buckets.items():
#             if v > majority:
#                 majority_elem = k
#                 majority = v
        
#         return majority_elem

# Moores voting algorithm!
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        candidate = 0
        for i, num in enumerate(nums):
            if count == 0:
                candidate = num
                count += 1
            elif num == candidate:
                count += 1
            else:
                count -= 1
        return candidate

@dataclass
class TestSample:
    nums: List[int]
    solution: int

class TestRunner:
    data: List[TestSample]

    def __init__(self):
        self.data = [
            TestSample([3,2,3], 3),
            TestSample([2,2,1,1,1,2,2], 2)
        ]

    def __check_result(self, sample: TestSample, k: int):
        return k == sample.solution

    def Run(self):
        print("Running tests...")
        s = Solution()
        for i, sample in enumerate(self.data):
            k = s.majorityElement(sample.nums)
            print(f"Test {i}: {self.__check_result(sample, k)}")

if __name__ == "__main__":
    runner = TestRunner()
    runner.Run()