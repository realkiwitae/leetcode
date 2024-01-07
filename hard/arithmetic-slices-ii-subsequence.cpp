#include <vector>
#include <unordered_map>

using namespace std;

/*
    leetcode: 446. Arithmetic Slices II - Subsequence
    https://leetcode.com/problems/arithmetic-slices-ii-subsequence
    ------

    Time: O(n^2)
    Space: O(n^2)

*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        using ll = long long;    
        vector<unordered_map<ll,int>> book(nums.size()); // reasons at idx count
    
        int ans = 0;

        for(size_t i = 1; i < nums.size();i++){
            for(size_t j = 0; j < i;j++){
                ll diff = (ll)nums[i] - (ll)nums[j];
                if(book[j].find(diff) == book[j].end()){
                    book[i][diff] += 1;
                }else{
                    book[i][diff] += 1 + book[j][diff];
                    ans += book[j][diff];
                }   
            }
        }

        return ans;
    }
};