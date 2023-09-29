from typing import List

# https://leetcode.com/problems/minimum-size-subarray-sum/
# class Solution:
#     def minSubArrayLen(self, target: int, nums: List[int]) -> int:
#         # Initialize window to first subarray that is >= target
#         l = 0
#         r = 0
#         sum = nums[0]
#         while sum < target:
#             r += 1
#             if r >= len(nums):
#                 return 0
#             sum += nums[r]
        
#         # Algorithm
#         #  - Shrink subarray if we can fit target in smaller subarray, update min_len if so
#         #  - Otherwise shift subarray one to the right
#         min_len = r + 1
#         current_min_sum = sum
#         while l <= r and l < len(nums) and r < len(nums):
#             if (current_min_sum - nums[l]) >= target:
#                 current_min_sum -= nums[l]
#                 l += 1
#                 min_len = r - l + 1
#             elif (current_min_sum - nums[r]) >= target:
#                 current_min_sum -= nums[r]
#                 r -= 1
#                 min_len = r - l + 1
#             else:
#                 current_min_sum -= nums[l]
#                 l += 1
#                 r += 1
#                 if r < len(nums):
#                     current_min_sum += nums[r]

#         return min_len

# DEFINITELY possible to optimise!
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l = 0
        sum = 0
        min_len = 0

        for i in range(len(nums)):
            if nums[i] >= target:
                return 1
            
            # Here we grow the window on the right
            sum += nums[i]

            # Here we shrink the window from the left as needed
            # This needs to be while because we may need to take more than 1 away
            while sum >= target:
                if min_len != 0:
                    min_len = min(min_len, i - l + 1)
                else:
                    min_len = i - l + 1
                sum -= nums[l]
                l += 1

        return min_len


import unittest

class Test(unittest.TestCase):

    def test_basic(self):
        s = Solution()
        self.assertEqual(s.minSubArrayLen(7, [2,3,1,2,4,3]), 2)
        self.assertEqual(s.minSubArrayLen(4, [1,4,4]), 1)
        self.assertEqual(s.minSubArrayLen(11, [1,1,1,1,1,1,1,1]), 0)

if __name__ == "__main__":
    unittest.main()
