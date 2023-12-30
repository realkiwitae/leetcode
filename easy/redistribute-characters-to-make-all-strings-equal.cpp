#include <vector>
#include <string>

using namespace std;

/*
    https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
    Time: O(n)
    Space: O(1)

    Count the number of each character in all strings.
    If the count of any character is not divisible by the number of strings, return false.
*/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int count[26] = {0};
        for(auto w : words){
            for(auto c : w)count[c-'a']++;
        }
        int n = words.size();
        for(int i = 0;i<26;i++){
            if(count[i]%n)return false;
        }
        return true;
    }
};