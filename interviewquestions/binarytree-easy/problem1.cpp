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

class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        int maxDepth = 1;
        TreeNode* stack[10];
        int stackptr = 0;
        TreeNode* current = root;

        stack[stackptr++] = current;
        current = current->left;

        while(current != nullptr || stackptr > 0)
        {
            while(current != nullptr)
            {
                stack[stackptr++] = current;
                current = current->left;
            }

            current = stack[--stackptr];
            std::cout << current->val << " ";
            if(stackptr+1 > maxDepth) { maxDepth = stackptr+1; }
            current = current->right;
        }
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