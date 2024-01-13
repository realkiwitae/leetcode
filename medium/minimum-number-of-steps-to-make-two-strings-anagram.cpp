#include <algorithm>
#include <string>

using namespace std;

/**
    leetcode: 1347 Minimum Number of Steps to Make Two Strings Anagram

    Time: O(n)
    Space: O(1)

*/

class Solution {
public:
    int minSteps(string s, string t) {
        int books[26] = {0};
        int bookt[26] = {0};
        for(size_t i =0; i < s.size();i++){
            books[s[i]-'a']++;
            bookt[t[i]-'a']++;
        }
        int ans = 0;
        for(int i = 0; i < 26;i++){
            ans += abs(books[i]-bookt[i]);
        }
        return ans/=2;
    }
};