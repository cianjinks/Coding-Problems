from typing import List

# https://leetcode.com/problems/jump-game-ii/
class Solution:
    def canJump(self, nums: List[int]) -> int:
        return 0

import unittest

class Test(unittest.TestCase):

    def test_basic(self):
        s = Solution()
        self.assertEqual(s.canJump([2,3,1,1,4]), 2)
        self.assertEqual(s.canJump([2,3,0,1,4]), 2)

if __name__ == "__main__":
    unittest.main()