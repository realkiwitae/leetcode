#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

/*
    Time: O(n) where n is the length of the string
    Space: O(n)

    Sliding window
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        unordered_map<char,int> book;

        int L = 0;
        int R = 0;
        int nbL = 0;
        int ans = 0;
        while(R < s.size()){
            book[s[R]]++;
            if(book[s[R]] == 1){
                if(++nbL>2){
                    ans = max(R - L,ans);
                    while(nbL>2){
                        book[s[L]]--;
                        if(!book[s[L++]])nbL--;
                    }
                }
            }
            R++;
        }
        ans = max(ans,R - L);
        return ans;
    }
};