#include <vector>
#include <algorithm>

using namespace std;

/*
    * 1. Find the first occurence of the element
    * 2. Find the last occurence of the element
    * 3. If the difference between the two is greater than n/4, return the element
    * 4. Else, return -1
    * 
    * Time Complexity: O(logn)
    * Space Complexity: O(1)
    * 
*/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        vector<int> candidates = {arr[n/4] , arr[n/2], arr[3*n/4]};

        for(int ans : candidates){
            int low = lower_bound(arr.begin(),arr.end(),ans) -  arr.begin();
            int upper = upper_bound(arr.begin(),arr.end(),ans)-arr.begin()-1;

            if(upper-low+1 > n/4.)return ans;

        }
        return -1;
    }
};