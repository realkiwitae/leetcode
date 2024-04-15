#include "utils.h"

/*
129. Sum Root to Leaf Numbers

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

Time complexity: O(n)
Space complexity: O(n)

*/

class Solution {
public:

    int dfs(TreeNode* root, int sum) {
        if (!root) return 0;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) {
            return sum;
        }
        return dfs(root->left, sum) + dfs(root->right, sum);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};