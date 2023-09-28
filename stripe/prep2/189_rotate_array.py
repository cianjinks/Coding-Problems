from typing import List
from dataclasses import dataclass

# I GIVE UP ON THIS ONE FOR NOW
# Everyone's solutions is just reversing slices of the array
# I guess that might be the best, but I don't like it

# https://leetcode.com/problems/rotate-array/
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        if len(nums) == 1: return
        if k == 0: return
        if k == len(nums): return

        n = len(nums)
        k = (k % n) # Shifting by array of length N by k is the same as shifting by (k % N)
        x = n - k

        for i in range(n - x):
            temp = nums[i]
            nums[i] = nums[(i + x) % n]
            nums[(i + x) % n] = temp

        for j in range(n - x, n - (n % k)):
            temp = nums[j]
            nums[j] = nums[j + (n % k)]
            nums[j + (n % k)] = temp

# [1, 2, 3, 4, 5, 6]
# [3, 4, 5, 6, 1, 2]
# [2, 3, 4, 5, 6, 1]

# k = 4
# n = 6
# x = n - k = 2

# nums[0] = nums[2]
# nums[1] = nums[3]
# nums[2] = nums[4]
# nums[3] = nums[5]
# nums[4] = nums[0] = nums[4]
# nums[5] = nums[1] = nums[5]

# k = 5
# n = 6
# x = n - k = 1

# nums[0] = nums[1]
# nums[1] = nums[2]
# nums[2] = nums[3]
# nums[3] = nums[4]
# nums[4] = nums[5]
# nums[5] = nums[0] = nums[5]

# x = n - k
# for i in range(n - x):
#   nums[i] = nums[(i + x) % n]

# for j in range(n - x, n):
#   nums[j] = nums[(j % k) + x]

# k = 3
# n = 7
# x = n - k = 4
# nums[0] = nums[4]
# nums[1] = nums[5]
# nums[2] = nums[6]
# nums[3] = nums[0]
# nums[4] = nums[1] = nums[5]
# nums[5] = nums[2] = nums[6]
# nums[6] = nums[3] = nums[6]

@dataclass
class TestSample:
    nums: List[int]
    k: int
    solution: List[int]

class TestRunner:
    data: List[TestSample]

    def __init__(self):
        self.data = [
            # TestSample([1,2,3,4,5,6,7], 3, [5,6,7,1,2,3,4]),
            # TestSample([-1,-100,3,99], 2, [3,99,-1,-100]),
            # TestSample([8, 2, 3, 3, 4, 5], 3, [3, 4, 5, 8, 2, 3]),
            # TestSample([1, 2], 3, [2, 1]),
            # TestSample([1, 2], 2, [1, 2]),
            # TestSample([1, 2, 3, 4, 5, 6], 4, [3, 4, 5, 6, 1, 2]),
            # TestSample([-1], 2, [-1]),
            TestSample([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27], 38, [17,18,19,20,21,22,23,24,25,26,27,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16])
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