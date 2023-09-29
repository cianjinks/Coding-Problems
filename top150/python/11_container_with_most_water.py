from typing import List

# https://leetcode.com/problems/container-with-most-water/
class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area = 0
        l = 0
        r = len(height) - 1
        while l < r:
            current_area = min(height[l], height[r]) * (r - l)
            max_area = max(max_area, current_area)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1

        return max_area

import unittest

class Test(unittest.TestCase):

    def test_basic(self):
        s = Solution()
        self.assertEqual(s.maxArea([1,8,6,2,5,4,8,3,7]), 49)
        self.assertEqual(s.maxArea([1,1]), 1)


if __name__ == "__main__":
    unittest.main()
