//https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/603/

#include <vector>

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

        if(head->next == nullptr)
        {
            return nullptr;
        }

        std::vector<ListNode*> array;
        ListNode* temp = head;
        while(temp->next != nullptr)
        {
            array.emplace_back(temp);
            temp = temp->next;
        }
        array.emplace_back(temp);
        ListNode* node = array[array.size() - n];
        if(node->next == nullptr)
        {
            node = array[array.size() - (n + 1)];
            node->next = nullptr;
        }
        else 
        {
            node->val = node->next->val;
            node->next = node->next->next;
        }

        return head;
    }
};

int main()
{
    ListNode nodeTwo(2);
    ListNode nodeOne(1);
    nodeOne.next = &nodeTwo;
    Solution s;
    s.removeNthFromEnd(&nodeOne, 1);
}