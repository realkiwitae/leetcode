#include <cmath>

/*
    leetcode 231. Power of Two
    https://leetcode.com/problems/power-of-two/

    Time: O(1)
    Space: O(1)

*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1)return false;
        return log2(n) == int(log2(n));
    }
};