#include <vector>
#include <algorithm>

using namespace std;

/*
    leetcode 2971 - Largest Perimeter

    Time: O(nlogn)
    Space: O(1)
*/


class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = nums[0]+nums[1];
        long long ans = -1;
        for(size_t i = 2; i < nums.size();i++){
            if(sum > nums[i])ans = sum+nums[i];
            sum+=nums[i];
        }
        return ans;
    }
};