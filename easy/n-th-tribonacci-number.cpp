#include <bits/stdc++.h>
using namespace std;

/*
    1137. N-th Tribonacci Number

    O(n) time and O(n) space
*/

class Solution {
public:
    int tribonacci(int n) {
        int dp[50];
        memset(dp,0,sizeof(dp));
        
        dp[1]=1;
        dp[2]=1;
        for(int i = 3; i <= n;i++){
            dp[i] = dp[i-1]+ dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};