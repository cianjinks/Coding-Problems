// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/625/
#include <iostream>
#include <vector>

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
    // Time Complexity: O(N) + O(N) = O(N)
    // Space Complexity: O(N)
    void recursiveInorder(TreeNode* root, std::vector<int>& values)
    {
        if(root->left != nullptr) { recursiveInorder(root->left, values); };
        values.emplace_back(root->val);
        if(root->right != nullptr) { recursiveInorder(root->right, values); }
    }

    bool isValidBST(TreeNode* root) 
    {
        if(root == nullptr) { return false; }
        std::vector<int> values;
        recursiveInorder(root, values);
        for(int i = 1; i < (int)values.size(); i++)
        {
            if(values[i] <= values[i - 1]) { return false; }
        }
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