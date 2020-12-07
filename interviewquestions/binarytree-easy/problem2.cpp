// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/625/
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
    bool isValidBST(TreeNode* root) {
        
    }
};

int main()
{
    Solution s;
    Solution s;
    TreeNode node1 = TreeNode(9, nullptr, nullptr);
    TreeNode node3 = TreeNode(15, nullptr, nullptr);
    TreeNode node4 = TreeNode(7, nullptr, nullptr);
    TreeNode node2 = TreeNode(20, &node3, &node4);
    TreeNode node(3, &node1, &node2);
    std::cout << "Valid: " << s.isValidBST(&node) << std::endl;

    return 0;
}