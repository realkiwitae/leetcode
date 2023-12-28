#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/string-compression-ii/
/*
    Time: O(n^2*k)
    Space: O(n*k)

    DP, memoization
    dp[i][k] = min number of characters to delete from i to the end of the string
    to get a string with at most k characters

    dp[i][k] = min(1+dp[i+1][k-1], 1+dp[j][k-1]) where j is the first index such that
    s[i] != s[j] and s[i] == s[j+1] and s[i] == s[j+2] and so on

    The first term is the case where we delete the character at index i
    The second term is the case where we delete the characters from i to j
    and then we delete the character at index j

    The second term is the one that makes this problem hard to solve in O(n*k)
    because we need to find the first index j such that s[i] != s[j] and s[i] == s[j+1]
    and s[i] == s[j+2] and so on

    We can use a prefix sum to find the first index j such that s[i] != s[j] and s[i] == s[j+1]
    and s[i] == s[j+2] and so on

    We can also use a prefix sum to find the number of characters from i to j

    The time complexity is O(n^2*k) because we need to iterate over all the possible values of j
    for each value of i and k

*/

class Solution {
public:

    int dfs(int i , int k,string& s,vector<vector<int>>& memo){
        if(k < 0)return 1e9;
        if(s.size()-i<=k) return 0;
        
        if(memo[i][k]!=-1) return memo[i][k];
		
        int val = dfs(i+1,k-1,s,memo);
        int c = 1;
        int n = k;
        for(int j=i+1;j<=(int)s.size();j++){
            val = min(val,1+(c>99)+(c>9)+(c>1)+dfs(j,n,s,memo));
			
            if(j<s.size() and s[i]==s[j]) c++;
            else if(--n<0) break;
        }
        return memo[i][k] = val;
    }

    int getLengthOfOptimalCompression(string s, int k) {
        vector<vector<int>> memo(101,vector<int>(101,-1));
        return dfs(0,k,s,memo);
    }
};