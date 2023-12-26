#include <vector>

using namespace std;

// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
/*
    Time: O(n*k*target)
    Space: O(n*target)

    DP

*/

class Solution {
public:
    int mod = 1e9+7;

    int dfs(int n , int k, int target, vector<vector<int>>& memo){
        if(target < 0 )return 0;
        if(target == 0 || n == 0)return n==0 && target == 0;

        if(memo[n][target]>-1)return memo[n][target];

        memo[n][target] = 0;
        for(int i = 1; i <= k ; i ++){
            memo[n][target] = (memo[n][target]+dfs(n-1,k,target-i,memo))%mod;
        }

        return memo[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(31,vector<int>(1001,-1));
        return dfs(n,k,target,memo);    
    }
};