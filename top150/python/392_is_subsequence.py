from typing import List

# https://leetcode.com/problems/is-subsequence/
# class Solution:
#     def isSubsequence(self, s: str, t: str) -> bool:

#         if len(s) == 0: return True
#         if len(t) == 0: return False

#         s_ptr = 0
#         t_ptr = 0

#         while (s_ptr < len(s)) and (t_ptr < len(t)):
#             if t[t_ptr] == s[s_ptr]:
#                 s_ptr += 1
#             t_ptr += 1

#         return s_ptr == len(s)

# Optimised Solution
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:

        if len(s) == 0: return True
        if len(t) == 0: return False

        s_ptr = 0
        for c in t:
            if s[s_ptr] == c:
                s_ptr += 1
                if s_ptr == len(s):
                    return True

        return False


import unittest

class Test(unittest.TestCase):

    def test_basic(self):
        s = Solution()
        self.assertEqual(s.isSubsequence("abc", "ahbgdc"), True)
        self.assertEqual(s.isSubsequence("axc", "ahbgdc"), False)\

if __name__ == "__main__":
    unittest.main()