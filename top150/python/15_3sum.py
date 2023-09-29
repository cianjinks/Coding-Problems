from typing import List

# The n^2 log(n) solution seems simple?
# Iterate i
 # Iterate j
  # Binary search for -i-j

# But how do we do it with two pointers?
# https://leetcode.com/problems/3sum/
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        return []

import unittest

class Test(unittest.TestCase):

    def test_basic(self):
        s = Solution()
        self.assertEqual(s.threeSum([-1,0,1,2,-1,-4]), [[-1,-1,2],[-1,0,1]])
        self.assertEqual(s.threeSum([0,1,1]), [0,1,1])
        self.assertEqual(s.threeSum([0,0,0]), [0,0,0])

if __name__ == "__main__":
    unittest.main()
