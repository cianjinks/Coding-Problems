//https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/772/
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// O(N) time with O(N) space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* copy = head;
        std::vector<int> values; 
        while(copy != nullptr)
        {
            values.emplace_back(copy->val);
            copy = copy->next;
        }
        int x = 0, y = values.size() - 1;
        int n = (int)(values.size() / 2);
        while(x != n)
        {
            if(values[x] != values[y])
            {
                return false;
            }
            x++;
            y--;
        }
        if(x == y && values[x] != values[y])
        {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(2);
    ListNode l4(1);

    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    s.isPalindrome(&l1);
}