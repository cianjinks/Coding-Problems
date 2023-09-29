from typing import List
from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        if head == None: return None
        if head.next == None: return head
        
        # Keep pointer to the latest lower than node
        # Keep pointer to the latest greater than equal
        # Join the chains together at the end
        lower = None
        orig_lower = None
        greater_equal = None
        orig_greater_equal = None

        while head != None:
            if head.val < x:
                if lower is None:
                    lower = head
                    orig_lower = lower
                else:
                    lower.next = head
                    lower = lower.next
            else:
                if greater_equal is None:
                    greater_equal = head
                    orig_greater_equal = greater_equal
                else:
                    greater_equal.next = head
                    greater_equal = greater_equal.next
            head = head.next
        
        if greater_equal is not None:
            greater_equal.next = None

        if lower is not None:
            lower.next = orig_greater_equal
            return orig_lower
        
        return orig_greater_equal

import unittest
import copy

class Test(unittest.TestCase):

    def __create_linked_list(self, list: List[int]):
        if len(list) == 0: 
            return None

        head = ListNode(list[0], next=None)
        new = head
        for i in range(1, len(list)):
            new.next = ListNode(list[i])
            new = new.next

        return head
    
    def __compare_linked_list(self, l1: ListNode, l2: ListNode):
        self.assertIsNotNone(l1)
        self.assertIsNotNone(l2)

        while l1 != None and l2 != None:
            self.assertEqual(l1.val, l2.val)
            l1 = l1.next
            l2 = l2.next
    
    def test_basic(self):
        s = Solution()
        l1 = self.__create_linked_list([1,4,3,2,5,2])
        result = s.partition(copy.deepcopy(l1), 3)
        self.__compare_linked_list(l1, result)

        l2 = self.__create_linked_list([2,1])
        result = s.partition(copy.deepcopy(l2), 2)
        self.__compare_linked_list(l2, result)


if __name__ == "__main__":
    unittest.main()
