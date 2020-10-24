#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// This solution actually dosen't merge based on value
/**
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        if(l2 == nullptr) { return l1; }
        if(l1 == nullptr) { return l2; }
        if(l2->next == nullptr)
        {
            l2->next = l1;
            return l2;
        }
        ListNode* head = l2;
        ListNode* l3;
        while(l2 != nullptr)
        {
            l3 = l2->next;
            l2->next = l1;
            l2 = l1->next;
            l1->next = l3;
            l1 = l3->next;
            l3->next = l2;
        }
        return head;
    }
};
**/

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