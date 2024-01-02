#include <vector>
#include <algorithm>

using namespace std;

/*
    leetcode 2022. Convert 1D Array Into 2D Array
    https://leetcode.com/problems/convert-1d-array-into-2d-array/

    Time: O(nlogn)
    Space: O(1)

*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        size_t L = 0;
        size_t R = 0;
        while(L < nums.size()){
            while(R < nums.size() && nums[R]==nums[L])R++;
            if(ans.size() < R-L)ans.resize(R-L);
            for(size_t i = 0; i < R-L;i++){
                ans[i].push_back(nums[L+i]);
            }
            L = R;
        }
        return ans;
        
    }
};