// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/560/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iterative Solution
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        ListNode* prev = head;
//        ListNode* current;
//        ListNode* next;
//
//        // Make sure the linked list is size > 2
//        if(prev == nullptr)
//        {
//            return head;
//        }
//        if(prev->next != nullptr)
//        {   
//            current = prev->next;
//        }
//        else { return head; };
//        if(current->next != nullptr)
//        {
//            next = current->next;
//        }   
//        else
//        {
//            prev->next = nullptr;
//            current->next = prev;
//            return current;
//        }
//
//        // Reverse iteratively
//        prev->next = nullptr;
//        while(next != nullptr)
//        {   
//            current->next = prev;
//            prev = current;
//            current = next;
//            next = next->next;
//        }
//        current->next = prev;
//        return current;
//    }
//};

// Recursive Solution
class Solution
{
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
        {
            return nullptr;
        }
        if(head->next == nullptr)
        {
            return head;
        }
        ListNode* node = reverseList(head->next);
        node->next = head;
        head->next = nullptr;
        return node;
    }
};

int main()
{
    ListNode head(1);
    ListNode node2(2);    
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);

    head.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    Solution s;
    ListNode* result = s.reverseList(&head);
    return 0;
}