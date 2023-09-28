from typing import List
from dataclasses import dataclass

# https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
# First solution, works!
# class Solution:
#     def removeDuplicates(self, nums: List[int]) -> int:
#         if len(nums) == 1: return 1
#         if len(nums) == 2: return 2

#         start_index = 2 if (nums[0] == nums[1]) else 1
#         index = start_index
#         for i in range(start_index, len(nums)):
#             if (nums[index - 1] != nums[i]):
#                 nums[index] = nums[i]
#                 if (i < len(nums) - 1) and (nums[i] == nums[i + 1]):
#                     nums[index + 1] = nums[i + 1]
#                     index += 2
#                 else:
#                     index += 1

#         return index

# Slightly optimized version, removing the annoying check for i in bounds:
# class Solution:
#     def removeDuplicates(self, nums: List[int]) -> int:
#         if len(nums) == 1: return 1
#         if len(nums) == 2: return 2

#         start_index = 2 if (nums[0] == nums[1]) else 1
#         index = start_index
#         for i in range(start_index, len(nums) - 1):
#             if (nums[index - 1] != nums[i]):
#                 nums[index] = nums[i]
#                 if (nums[i] == nums[i + 1]):
#                     nums[index + 1] = nums[i + 1]
#                     index += 1
#                 index += 1

#         if (nums[index - 1] != nums[-1]):
#             nums[index] = nums[-1]
#             index += 1

#         return index

# Best solution? Wow, it's same as the solution to 26 but just - 2 :/
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0
        for num in nums:
            if i < 2 or num > nums[i - 2]:
                nums[i] = num
                i += 1
        return i

@dataclass
class TestSample:
    nums: List[int]
    expectedNums: List[int]

class TestRunner:
    data: List[TestSample]

    def __init__(self):
        self.data = [
            TestSample([1,1,1,2,2,3], [1,1,2,2,3]),
            TestSample([0,0,1,1,1,1,2,3,3], [0,0,1,1,2,3,3]),
            TestSample([1,2,2], [1,2,2])
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