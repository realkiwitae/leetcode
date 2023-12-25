#include <string>
#include <algorithm>

using namespace std;

// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

/*
    Time: O(n) where n is the length of the string
    Space: O(1)

    There are two possible starting strings 0 or 1
*/

class Solution {
public:

    int minOperations(string s) {
        int start[2] = {0,0};

        for(int i = 0; i < (int)s.size();i++){

            start[1] += (s[i] == '0' + (i%2));
            start[0] += (s[i] == '0'+((i+1)%2));
        }

        return min(start[0],start[1]); 
    }
};