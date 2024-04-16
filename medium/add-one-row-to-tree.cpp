#include "utils.h"

/*
    leetcode 623. Add One Row to Tree

    Time complexity: O(n)
    Space complexity: O(n)

    dfs to the target depth, then add the new node to the left and right of the current node
*/

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)return root;
        if(depth == 1){
            return new TreeNode(val,root,nullptr);
        }
        
        if(depth == 2){
            root->left = new TreeNode(val,root->left,nullptr);
            root->right = new TreeNode(val,nullptr,root->right);
            return root;
        }

        root->left = addOneRow(root->left, val, depth-1);
        root->right = addOneRow(root->right,val,depth-1);
        return root; 

    }
};