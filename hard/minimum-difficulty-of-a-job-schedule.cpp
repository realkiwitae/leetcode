#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

/*

    https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
    Time: O(n^2*d)
    Space: O(n*d)

    DP, memoization


*/

class Solution {
public:

    int dfs(int i, int d ,vector<int>& jobDifficulty , vector<vector<int>>& memo){
        int n = jobDifficulty.size();
        if(memo[i][d] != -1)return memo[i][d];

        if(d == 1){
            return *max_element(jobDifficulty.begin()+i, jobDifficulty.end());
        }

        memo[i][d] = INT_MAX;
        int check = 0;
        for(int j = i; j < n - d+1;j++){
            check = max(check, jobDifficulty[j]);
            memo[i][d] = min(memo[i][d],check + dfs(j+1,d-1,jobDifficulty,memo));
        }
        return memo[i][d];
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int K = jobDifficulty.size();
        if(K < d)return -1;

        vector<vector<int>> memo(K,vector<int>(d+1,-1));
        return dfs(0,d,jobDifficulty,memo);
    }
};