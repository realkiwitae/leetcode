#include <vector>

using namespace std;

/*
    leetcode 268. Missing Number
    https://leetcode.com/problems/missing-number/

    Time: O(n)
    Space: O(1)

*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n = nums.size();
        long long ans = n*(n+1)/2;
        for(int i : nums)ans-=i;
        return ans;
    }
};