from typing import List
import re

# https://leetcode.com/problems/valid-palindrome/
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        s = re.sub(r'[\W_]', '', s)

        if len(s) == 0: return True
        if len(s) == 1: return True

        start = 0
        end = len(s) - 1

        while start < end:
            if s[start] != s[end]:
                return False

            start += 1
            end -= 1

        return True

# Works, but we can also use char.isalpha() or char.isnumeric() instead of regular expression

import unittest

class Test(unittest.TestCase):

    def test_basic(self):
        s = Solution()
        self.assertEqual(s.isPalindrome("A man, a plan, a canal: Panama"), True)
        self.assertEqual(s.isPalindrome("race a car"), False)
        self.assertEqual(s.isPalindrome(" "), True)

if __name__ == "__main__":
    unittest.main()