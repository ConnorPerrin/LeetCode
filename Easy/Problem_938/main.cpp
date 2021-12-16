#include <stack>
#include <iostream>
#include <binaryTree.hpp>

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;

        if(root->val < low) {
            return rangeSumBST(root->right, low, high);
        }

        if(root->val > high)
            return rangeSumBST(root->left, low, high);
        
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

int main() {
    std::cout << "LeetCode Problem 938 - Range Sum of BST" << std::endl;
    Solution s;

    TreeNode* root = stringToTreeNode("[10,5,15,3,7,null,18]");
    int answer = s.rangeSumBST(root, 7, 15);

    std::cout << "Answer: " << answer << std::endl;

    return 0;
}