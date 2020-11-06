//https://leetcode.com/submissions/detail/417503400/?from=/explore/interview/card/top-interview-questions-easy/93/linked-list/771/
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* result;

        // Edge cases
        if(l1 == nullptr) { return l2; }
        else if(l2 == nullptr) { return l1; }
        //

        if(l1->val <= l2->val)
        {
            result = l1;
            l1 = l1->next;
        }
        else
        {
            result = l2;
            l2 = l2->next;
        }

        ListNode* head = result;
        
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val <= l2->val)
            {
                result->next = l1;
                result = result->next;
                l1 = l1->next;
            }
            else
            {
                result->next = l2;
                result = result->next;
                l2 = l2->next;
            }
        }

        if(l1 != nullptr)
        {
            result->next = l1;
        } 
        else 
        {
            result->next = l2;
        }
        return head;
    }
};

int main()
{
    Solution s;
    ListNode l1(1);
    ListNode l1_2(2);
    ListNode l1_3(4);
    ListNode l2(1);
    ListNode l2_2(3);
    ListNode l2_3(4);

    l1.next = &l1_2;
    l1_2.next = &l1_3;
    l2.next = &l2_2;
    l2_2.next = &l2_3;
    s.mergeTwoLists(&l1, &l2);
}