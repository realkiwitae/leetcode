#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
/*
    Time: O(n)
    Space: O(1)

    Greedy, just need to keep the maximum of each color streak and substract it from the total sum
*/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        size_t L = 0;
        size_t R = 0;
        int ans = 0;
        int maxi = 0;
        while(L < colors.size()){
            int maxi = 0;
            while(R < colors.size() && colors[L]==colors[R]){
                ans += neededTime[R];
                maxi = max(maxi,neededTime[R]);
                R++;
            }
            ans -= maxi;
            L = R;
        }
        ans -= maxi;
        return ans;
    }
};