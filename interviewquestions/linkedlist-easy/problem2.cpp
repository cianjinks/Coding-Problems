//https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/603/

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nodes[30];
        ListNode* temp = head;
        int index = 0;
        while(temp->next != nullptr)
        {
            nodes[index] = temp;
            temp = temp->next;
            index++;
        }
        deleteNode(nodes[index-n+1]);
        return nodes[0];
    }
};