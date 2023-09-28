from typing import List

# https://leetcode.com/problems/jump-game/
# class Solution:
#     def canJump(self, nums: List[int]) -> bool:
#         # Seems like a DFS problem?

#         visited = [False] * len(nums)
#         stack = []
#         stack.append(0)

#         while len(stack) != 0:
#             index = stack.pop()

#             if index >= len(nums) - 1:
#                 return True

#             if not visited[index]:
#                 visited[index] = True

#                 num = nums[index]
#                 for i in range(num):
#                     stack.append(index + i + 1)

#         return False

# Using DFS is not necessary because we already have our final node! It's nums[-1]
# Therefore we can just work backwards from that node up the tree
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        goal = len(nums) - 1

        index = len(nums) - 2
        while index >= 0:
            if index + nums[index] >= goal:
                goal = index
            index -= 1

        if goal == 0:
            return True
        return False

import unittest

class Test(unittest.TestCase):

    def test_basic(self):
        s = Solution()
        self.assertEqual(s.canJump([2,3,1,1,4]), True)
        self.assertEqual(s.canJump([3,2,1,0,4]), False)
        self.assertEqual(s.canJump([2,5,0,0]), True)
        self.assertEqual(s.canJump([2,3,0,4,0]), True)

        # 2


if __name__ == "__main__":
    unittest.main()