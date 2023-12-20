/* 
Time complexity O(1)
Space complexity O(1)

*/

class Solution {
public:
    int totalMoney(int n) {
        // 28
        int w = n/7 , r = n%7;
        return 28*w + 7*w*(w-1)/2 + r*w + r*(r+1)/2;
    }
};