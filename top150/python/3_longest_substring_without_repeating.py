from typing import List

# https://leetcode.com/problems/longest-substring-without-repeating-characters/
# class Solution:
#     def lengthOfLongestSubstring(self, s: str) -> int:
#         # Using a dictionary to track whether there are duplicates in the range
#         dict = {}
#         max_len = 0
#         left = 0
#         for r in range(len(s)):

#             if s[r] in dict:
#                 dict[s[r]] += 1
#             else:
#                 dict[s[r]] = 0

#             while len(dict) != (r - left + 1): # While the range contains duplicates
#                 if dict[s[left]] == 0:
#                     del dict[s[left]]
#                 else:
#                     dict[s[left]] -= 1
#                 left += 1

#             max_len = max(max_len, r - left + 1)
#         return max_len
    

# Previous solution works, but optimise!
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        # Using a dictionary to track the last index we saw a given character at
        seen = {}
        max_len = 0
        left = 0
        for r in range(len(s)):
            char = s[r]

            # Check the last index we saw this character at and if it is within the window
            if char in seen and seen[char] >= left:
                # If it is, we can jump left pointer to the last index of the duplicate character + 1
                # Because any window with left pointer = (r) up to (last index of duplicate) contains a duplicate!
                left = seen[char] + 1
            else:
                max_len = max(max_len, r - left + 1)

            seen[char] = r

        return max_len

import unittest

class Test(unittest.TestCase):

    def test_basic(self):
        s = Solution()
        self.assertEqual(s.lengthOfLongestSubstring("abcabcbb"), 3)
        self.assertEqual(s.lengthOfLongestSubstring("bbbbb"), 1)
        self.assertEqual(s.lengthOfLongestSubstring("pwwkew"), 3)

if __name__ == "__main__":
    unittest.main()
