#include "utils.h"
#include <string>

using namespace std;

/*
    leetcode 988. Smallest String Starting From Leaf

    Time complexity: O(n*n)
    Space complexity: O(n*n)
*/

class Solution {
public:

    string ans = "{";

    void dfs(TreeNode* root,string word){
        if(!root)return;
        word.insert (0, 1, 'a'+root->val);
        if(!root->left && !root->right){
            if(word < ans)ans = word;
            return;
        }
        dfs(root->left,word);
        dfs(root->right,word);
    }

    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
};