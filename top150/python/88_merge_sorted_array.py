from typing import List
from dataclasses import dataclass

# https://leetcode.com/problems/merge-sorted-array/
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        # If n is 0, do nothing
        # if (n == 0): return

        # if m is 0, copy nums2 into nums1
        # if (m == 0):
        #     for i in range(n): nums1[i] = nums2[i]
        #     return

        m_ptr = m - 1
        n_ptr = n - 1

        i = m + n - 1
        while i >= 0:

            if ((n_ptr < 0) and (m_ptr >= 0)):
                nums1[i] = nums1[m_ptr]
                m_ptr -= 1
            elif ((m_ptr >= 0) and (nums1[m_ptr] >= nums2[n_ptr])):
                nums1[i] = nums1[m_ptr]
                m_ptr -= 1
            elif (n_ptr >= 0):
                nums1[i] = nums2[n_ptr]
                n_ptr -= 1

            i -= 1

@dataclass
class TestCase:
    nums1: List[int]
    m: int
    nums2: List[int]
    n: int

tests: List[TestCase] = [
    TestCase([1,2,3,0,0,0], 3, [2,5,6], 3),
    TestCase([1], 1, [], 0),
    TestCase([0], 0, [1], 1),
    TestCase([1,2,5,6,0,0,0,0], 4, [3,4,7,8], 4)
]

def check_result(nums: List[TestCase]) -> bool:
    index = 0
    while index < (len(nums) - 1):
        if (nums[index] > nums[index + 1]):
            return False
        index += 1
    return True


def main():
    s = Solution()
    print("Running tests...")
    for t, test in enumerate(tests):

        s.merge(test.nums1, test.m, test.nums2, test.n)
        print(f"Test {t}: {check_result(test.nums1)}")

if __name__ == "__main__":
    main()