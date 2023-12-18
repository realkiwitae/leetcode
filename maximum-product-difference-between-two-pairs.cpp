#include <vector>
#include <algorithm>

using namespace std;

/*
    Time Complexity: O(nlogn) // could do O(n) with linear selection but lazy
    Space Complexity: O(1)

*/


class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        return nums.back()*nums[nums.size()-2] - nums[1]*nums[0];
    }
};