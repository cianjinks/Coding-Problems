# https://leetcode.com/problems/two-sum/

from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        print(f"The nums are {nums} and the target is {target}")

        # Optimized solution
        dictionary = {}
        # O(n)
        for index, n in enumerate(nums):
            diff = target - n
            if n in dictionary: return (dictionary[n], index) # Dict lookup is O(1) in Python3 (for an ordered dict it would be O(log(N))
            dictionary[diff] = index
        return None

        # Brute force solution
        # for idx1, i in enumerate(nums):
        #     for idx2, j in enumerate(nums):
        #         if (idx1 != idx2):
        #             if (i + j == target):
        #                 return (idx1, idx2)
        # return None

def test_solution():
    s = Solution()
    tests = [
        ([2, 7, 11, 15], 9),
        ([3, 2, 4], 6),
        ([3, 3], 6),
        ([], 0)
    ]
    for index, t in enumerate(tests):
        result = s.twoSum(t[0], t[1])
        print(f"Test {index}: {result}")

if __name__ == "__main__":
    test_solution()