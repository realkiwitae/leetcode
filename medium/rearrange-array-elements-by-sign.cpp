#include <vector>

using namespace std;

/*
    leetcode 2149 - Rearrange Array Elements by Sign

    Time: O(n)
    Space: O(n)
*/


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int pos = -2, neg = -1;

        for(int i : nums){
            if(i>=0)ans[pos+=2] = i;
            else ans[neg+=2] = i;
        }
        return ans;
    }
};