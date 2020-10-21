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
        ListNode* iterator = l1;
        ListNode* iterator2 = l1->next;
        iterator->next = l2;
        l2 = l2->next;
        while(iterator->next != nullptr)
        {
            iterator->next = l2->next;
            l2 = l2->next;
            l2->next = iterator2;

        }
    }
};

int main()
{

}