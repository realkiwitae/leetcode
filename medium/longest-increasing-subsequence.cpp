#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

/*
    leetcode 300. Longest Increasing Subsequence
    https://leetcode.com/problems/longest-increasing-subsequence

    Given an unsorted array of integers, find the length of longest increasing subsequence.

    Time complexity: O(nlogn)
    Space complexity: O(n)

*/

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq(nums.size()+1,INT_MAX);
        seq[0] = INT_MIN;
        int res = 1;
        for(int i = 0;i <nums.size();i++){
            int j = lower_bound(seq.begin(),seq.end(),nums[i])-seq.begin();
            res = max(res,j);
            if(seq[j] > nums[i])seq[j] = nums[i];
        }
        return res;
    }
};