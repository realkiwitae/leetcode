#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
    leetcode 1551. Minimum Operations to Make Array Equal
    time: O(n)
    space: O(n)

    1. count the frequency of each number
    2. for each number, the number of operations is (freq-2)/3 + (freq-(freq-2)/3*3)/2
    3. return the sum of all numbers
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> book;
        for(int i : nums)book[i]++;
        int ans = 0;
        for(auto it : book){
            if(it.second < 2)return -1;
            ans += (it.second -2)/3 + (it.second - (it.second -2)/3*3)/2;
        }
        return ans;
    }
};