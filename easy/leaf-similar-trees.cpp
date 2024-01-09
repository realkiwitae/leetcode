#include "utils.h"
#include <vector>

using namespace std;

/**
 * 
 * leeetcode: 872 Leaf-Similar Trees
 * 
 * Time: O(n)
 * Space: O(n)
*/

class Solution {
public:

    void dfs(TreeNode* node,vector<int>& leaves){
        if(!node)return;
        if(!node->left && ! node->right){leaves.push_back(node->val);return;}

        dfs(node->left,leaves);
        dfs(node->right,leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1,leaves2;
        dfs(root1,leaves1);
        dfs(root2,leaves2);
        return leaves1 == leaves2; 
    }
};