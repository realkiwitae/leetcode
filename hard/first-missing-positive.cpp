#include <vector>
#include <cmath>

using namespace std;

/*
    leetcode: 41  First Missing Positive

    Time: O(n)
    Space: O(1)

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool seen1 = false;
        for(int& i : nums){
            if(i==1)seen1 = true;
            if(i<1 || i >(int)nums.size()) i=1;
        }
        if(!seen1)return 1;
        
        for(size_t i =0;i < nums.size();i++){
            int n = abs(nums[i]);
            nums[n-1] = -abs(nums[n-1]);
        }
        for(size_t i = 0; i <nums.size();i++){
            if(nums[i]>0)return i+1;
        }
        return nums.size()+1;
    }
};