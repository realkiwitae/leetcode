#include <vector>
#include <algorithm>

using namespace std;

/*
    Time complexity O(nlogn) (n is size of prices)
    Space complexity O(1)
*/

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int tmp = prices[0] + prices[1];
        if(tmp >money)return money;
        return money - tmp; 
    }
};