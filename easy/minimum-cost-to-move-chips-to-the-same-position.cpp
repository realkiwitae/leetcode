#include <vector>

using namespace std;

/*
    leetcode: 1217. Minimum Cost to Move Chips to The Same Position
    https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
    space: O(1)
    time: O(n)

*/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even =0;
        int odd = 0;

        for(int i : position){
            if(i%2)odd++;
            else even++;
        }

        return min(odd,even);
    }
};