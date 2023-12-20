#include <vector>

using namespace std;

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

    double ans = 0;
    //tot + count nodes
    pair<int,int> help(TreeNode* root){
        if(!root)return {0,0};
        double val = root->val;
        int i = 1;
        if(root->left){
            auto [s,l] = help(root->left);
            val += s;
            i+= l;
        }
        if(root->right){
            auto [s,r] = help(root->right);
            val +=s;
            i+=r;
        }
        ans = max(val/i,ans);
        return {val,i};
    }

    double maximumAverageSubtree(TreeNode* root) {
        help(root);
        return ans;
    }
};