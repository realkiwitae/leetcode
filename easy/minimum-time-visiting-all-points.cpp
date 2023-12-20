#include <vector>
#include <cmath>

using namespace std;

/* 
link: https://leetcode.com/problems/minimum-time-visiting-all-points/

Time complexity O(n)
Space complexity O(1)

*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for(int i = 1;i<n;i++){
            int dx = abs(points[i][0]-points[i-1][0]);
            int dy = abs(points[i][1]-points[i-1][1]);
            ans += min(dx,dy)+abs(dx-dy);
        }

        return ans;

    }
};