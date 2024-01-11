#include "utils.h"
#include <algorithm>

using namespace std;

/*
    leeetcode: 1026 Maximum Difference Between Node and Ancestor
     
    Time: O(n)
    Space: O(n)
    

*/

class Solution {
public:

    int dfs(TreeNode* root, int minval , int maxval){
        if(!root)return 0;
        int ans = max(abs(minval-root->val),abs(maxval-root->val));
        minval = min(root->val,minval);
        maxval = max(root->val,maxval);
        ans = max(ans,dfs(root->left,minval,maxval));
        ans = max(ans,dfs(root->right,minval,maxval));
        return ans;
    }

    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val,root->val);
    }
};