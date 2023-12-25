#include <string>
#include <cstring>

using namespace std;

/*
    https://leetcode.com/problems/decode-ways/
    Time: O(n) where n is the length of the string
    Space: O(n) dynamic programming 
*/

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
       
        int n = s.size();

        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        int a = s[0] - '0';
        dp[1] = a>0;

        for(int i = 2; i <= n; i++){
            int a = s[i-1] - '0';
            if(a != 0) dp[i] = dp[i-1];
            int b = s[i-2] - '0';
            if(b == 0)continue;
            a+=10*b;
            if(a>9 && a<27)dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};