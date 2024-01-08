#include "utils.h"

/*
    Leeetcode: 938 Range Sum of BST

    Time: O(n)
    Space: O(n)

*/

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)return 0;
        int ans = 0;
        if(root->val >= low && root->val <= high)ans = root->val;
        if(root->val > low)ans += rangeSumBST(root->left,low,high);
        if(root->val < high)ans += rangeSumBST(root->right,low,high);

        return ans;
    }
};