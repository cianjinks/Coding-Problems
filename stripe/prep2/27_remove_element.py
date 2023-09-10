from typing import List
from dataclasses import dataclass

# https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150

# Whoops I overcomplicated it with more complex two pointer solution :/
# class Solution:
#     def removeElement(self, nums: List[int], val: int) -> int:
#         p1 = 0
#         p2 = 0

#         while (p1 < len(nums) and p2 < len(nums)):
#             if (nums[p1] == val):
#                 if (nums[p1] != nums[p2]):
#                     temp = nums[p1]
#                     nums[p1] = nums[p2]
#                     nums[p2] = temp
#                     p1 += 1
#                 else:
#                     p2 += 1
#             else:
#                 p1 += 1
#                 p2 += 1

#         return p1

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        index = 0
        for i, num in enumerate(nums):
            if (num != val):
                nums[index] = num
                index += 1
        return index

@dataclass
class TestSample:
    nums: List[int]
    val: int
    solution: int

class TestRunner:
    tests: List[TestSample]

    def __init__(self):
        self.tests = [
            TestSample([3,2,2,3], 3, 2),
            TestSample([0,1,2,2,3,0,4,2], 2, 5),
            TestSample([], 0, 0)
        ]

    def run(self):
        print("Running...")
        s = Solution()
        for t, test_sample in enumerate(self.tests):
            k = s.removeElement(test_sample.nums, test_sample.val)
            print(f"Test {t}: {self.__check_result(test_sample, k)}")

    def __check_result(self, sample: TestSample, result: int):
        if (result != sample.solution): return False

        for i in range(sample.solution):
            if (sample.nums[i] == sample.val):
                return False

        return True

if __name__ == "__main__":
    runner = TestRunner()
    runner.run()