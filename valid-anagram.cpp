#include <string>

using namespace std;

/*
    Time Complexity: O(n + m)
    Space Complexity: O(1)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int book[26] = {0};

        for(char c : s)book[c-'a']++;
        for(char c : t)book[c-'a']--;

        for(int i = 0; i < 26;i++){
            if(book[i])return false;
        }

        return true;
    }
};