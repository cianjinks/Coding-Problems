#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* twoPointerTraverse(ListNode* A, ListNode* B, int difference)
    {
        ListNode* a_traversal = A;
        ListNode* b_traversal = B;
        while(difference != 0)
        {
            if(a_traversal == b_traversal)
            {
                return a_traversal;
            }
            a_traversal = a_traversal->next;
            difference--;
        }

        bool flip = true;
        while(a_traversal != nullptr && b_traversal != nullptr)
        {
            if(a_traversal == b_traversal)
            {
                return a_traversal;
            }
            if(flip) { a_traversal = a_traversal->next; }
            else { b_traversal = b_traversal->next; }
            flip = !flip;
        }
        return nullptr;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA == nullptr) { return NULL; }
        if(headB == nullptr) { return NULL; }

        // Get size of A
        ListNode* a_traversal = headA;
        int sizeA = 0;
        while(a_traversal != nullptr)
        {
            sizeA++;
            a_traversal = a_traversal->next;
        }

        // Get size of B
        ListNode* b_traversal = headB;
        int sizeB = 0;
        while(b_traversal != nullptr)
        {
            sizeB++;
            b_traversal = b_traversal->next;
        }

        int difference = abs(sizeA-sizeB);
        if(sizeA >= sizeB)
        {
            return twoPointerTraverse(headA, headB, difference);
        }
        //else if(sizeA < sizeB)
        return twoPointerTraverse(headB, headA, difference);
    }
};

int main()
{
    return 0;
}
