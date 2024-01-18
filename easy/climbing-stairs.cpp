/*
    leetcode 70. Climbing Stairs

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int climbStairs(int n) {

        int dp[2] = {1,2};
        for(int i = 2; i < n; i++){
            dp[i%2] += dp[(i+1)%2];
        }
        return dp[(n-1)%2];
    }
};