from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        s = 0
        e = len(numbers) - 1

        while s < e:
            sum = numbers[s] + numbers[e]
            if sum < target:
                s += 1
            elif sum > target:
                e -= 1
            else:
                break

        return [s+1, e+1]

import unittest

class Test(unittest.TestCase):

    def test_basic(self):
        s = Solution()
        self.assertEqual(s.twoSum([2,7,11,15], 9), [1,2])
        self.assertEqual(s.twoSum([2,3,4], 6), [1,3])
        self.assertEqual(s.twoSum([-1,0], -1), [1,2])

if __name__ == "__main__":
    unittest.main()