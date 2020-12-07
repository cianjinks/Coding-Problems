// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/555/
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution 1
/**
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        return maxDepth(root, 0);
    }

    int maxDepth(TreeNode* node, int height)
    {
        if(node == nullptr) { return height; }
        int leftHeight = maxDepth(node->left, height+1);
        int rightHeight = maxDepth(node->right, height+1);
        return std::max(leftHeight, rightHeight);
    }
};
**/

// Solution 2
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr) { return 0; }
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{
    Solution s;
    TreeNode node1 = TreeNode(9, nullptr, nullptr);
    TreeNode node3 = TreeNode(15, nullptr, nullptr);
    TreeNode node4 = TreeNode(7, nullptr, nullptr);
    TreeNode node2 = TreeNode(20, &node3, &node4);
    TreeNode node(3, &node1, &node2);
    s.maxDepth(&node);

    return 0;
}