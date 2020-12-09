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
    bool isValidBST(TreeNode* root) 
    {
        if(root == nullptr) { return true; }
        if(root->left != nullptr && root->left->val >= root->val) { return false; }
        if(root->right != nullptr && root->right->val <= root->val) { return false; }
        if(!isValidBST(root->right) || !isValidBST(root->left)) { return false; }
        return true;
    }
};

int main()
{
    Solution s;
    TreeNode node5 = TreeNode(3, nullptr, nullptr);
    TreeNode node4 = TreeNode(6, nullptr, nullptr);
    TreeNode node3 = TreeNode(4, &node5, &node4);
    TreeNode node2 = TreeNode(1, nullptr, nullptr);
    TreeNode node1 = TreeNode(5, &node2, &node3);
    std::cout << "Valid: " << s.isValidBST(&node1) << std::endl;

    return 0;
}