#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
    leetcode: 1216. Valid Palindrome III
    https://leetcode.com/problems/valid-palindrome-iii/
    space: O(n)
    time: O(n^2)
*/

class Solution {
public:

    bool isValidPalindrome(string s, int k) {
        vector<int> memo(s.length(),0);
        int temp,prev;
        for(int i = s.length()-2;i>=0;i--){
            prev = 0;
            for(int j = i+1; j < s.length();j++){
                temp = memo[j];
                if(s[i]==s[j])memo[j] = prev;
                else memo[j] = 1 + min(memo[j],memo[j-1]);
                prev = temp;
            }
        }
        return memo[s.length()-1] <= k;
    }
};