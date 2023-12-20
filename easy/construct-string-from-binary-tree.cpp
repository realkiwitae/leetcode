#include <string>

using namespace std;


/*
    Time complexity O(n) (n is size of root)
    Space complexity O(n) callstack
*/

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
    string tree2str(TreeNode* root) {
        if(!root)return "";
        string ans = to_string(root->val);
        if(!root->left&&!root->right)return ans;

        ans.push_back('(');
        ans.append(tree2str(root->left));
        ans.push_back(')');
        if(!root->right)return ans;
        ans.push_back('(');
        ans.append(tree2str(root->right));
        ans.push_back(')'); 
        return ans;
    }
};