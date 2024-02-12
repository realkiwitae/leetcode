#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt_curr = 1;
        int ans = nums[0];

        for(size_t i = 1;i < nums.size();i++){
            if(nums[i] == ans)cnt_curr++;
            else{
                if(--cnt_curr < 0){
                    ans = nums[i];
                    cnt_curr = 1;
                }
            }
        }
        return ans;
    }
};