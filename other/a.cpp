// Sum of range in a BST

#include <iostream>

struct Node
{
public:
    Node *left = nullptr;
    Node *right = nullptr;
    int val;

    Node(int val) : val(val) {}
};

int rangeSumBST(Node *root, int lowerBound, int upperBound)
{
    if (root->val < lowerBound)
    {
        if (root->right)
        {
            return rangeSumBST(root->right, lowerBound, upperBound);
        }
        return 0;
    }
    else if (root->val > upperBound)
    {
        if (root->left)
        {
            return rangeSumBST(root->left, lowerBound, upperBound);
        }
        return 0;
    }
    else
    {
        int r = 0;
        int l = 0;
        if (root->right)
        {
            r = rangeSumBST(root->right, lowerBound, upperBound);
        }
        if (root->left)
        {
            l = rangeSumBST(root->left, lowerBound, upperBound);
        }
        return r + l + root->val;
    }
}

void testFunc(Node *root, int lowerBound, int upperBound)
{
    int sum = 0;
    for (int i = lowerBound; i <= upperBound; i++)
    {
        sum += i;
    }
    std::cout << "Result of (" << lowerBound << ", " << upperBound << "): " << rangeSumBST(root, lowerBound, upperBound) << " | Expected: " << sum << std::endl;
}

int main()
{
    Node *bst = new Node(8);
    bst->left = new Node(3);
    bst->left->left = new Node(1);
    bst->left->right = new Node(6);
    bst->left->right->left = new Node(4);
    bst->left->right->right = new Node(7);
    bst->right = new Node(10);
    bst->right->right = new Node(14);
    bst->right->right->left = new Node(13);

    // Tests
    testFunc(bst, 13, 14);
    testFunc(bst, 3, 10);
    testFunc(bst, -1, 0);
}