#include "utils.h"
#include <algorithm>


using namespace std;

/*
    * leeetcode: 1530 Number of Good Leaf Nodes Pairs
    * 
    * Time: O(n)
    * Space: O(n)
    
*/

class Solution {
public:

    int dfs(TreeNode* root, int start,int& ans){
        if(!root)return 0;
        int depth = 0;

        int L = dfs(root->left,start,ans);
        int R = dfs(root->right,start,ans);

        if(root->val == start){
            depth = -1;
            ans = max(L,R);
        }else if(L>=0&&R>=0) depth = max(L,R)+1;
        else{
            ans = max(abs(L)+abs(R),ans);
            depth = min(L,R) -1;
        }
        return depth;
    }
    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;

        dfs(root,start,ans);

        return ans;
    }
};