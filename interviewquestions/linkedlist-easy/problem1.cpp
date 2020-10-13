 struct ListNode 
 {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Attempt 1
/**
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        ListNode* tempNode = node;
        ListNode* previousNode = node;
        while(tempNode->next != nullptr)
        {
            tempNode->val = tempNode->next->val;
            previousNode = tempNode;
            tempNode = tempNode->next;
        }
        previousNode->next = nullptr;
    }
};
**/

class Solution
{
public:
    void deleteNode(ListNode* node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }     
};