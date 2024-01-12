#include <string>
#include <algorithm>

using namespace std;

/*
    leetcode: 1704 Determine if String Halves Are Alike

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    const string vowels = "aeiouAEIOU";
    bool halvesAreAlike(string s) {
        int count = 0;
        for(int i = 0; i < s.size();i++){
            if(find(vowels.begin(),vowels.end(),s[i]) == vowels.end())continue;
            count += i<s.size()/2 ? 1:-1;
        }
        return !count;
    }
};