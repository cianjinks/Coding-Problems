from typing import List

# https://leetcode.com/problems/h-index/
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=True)

        h = 0
        while h < len(citations):
            if citations[h] <= h:
                break
            h += 1

        return h

    # [3, 1, 1]

import unittest

class Test(unittest.TestCase):

    def test_basic(self):
        s = Solution()
        self.assertEqual(s.hIndex([3,0,6,1,5]), 3)
        self.assertEqual(s.hIndex([1,3,1]), 1)
        self.assertEqual(s.hIndex([1]), 1)

if __name__ == "__main__":
    unittest.main()