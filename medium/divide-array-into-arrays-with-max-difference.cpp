#include <vector>
#include <algorithm> 

using namespace std;

/*
    leetcode.com/problems/divide-array-into-increasing-sequences

    Time: O(nlogn)
    Space: O(1)
*/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        if(nums.size()%3)return {};
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        size_t i = 0;
        while(i<nums.size()){
            if(nums[i+2]-nums[i]>k)return {};
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
            i+=3;
        }
        return ans;

    }
};