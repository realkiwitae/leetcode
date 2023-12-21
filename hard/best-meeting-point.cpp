#include <vector>
#include <algorithm>

using namespace std;

/*
    Time complexity O(m*n + klogk) (m is number of rows, n is number of cols, k is number of 1s)
    Space complexity O(k)
*/

class Solution {
public:
    int minDist(vector<int> rows){
        int ans = 0;
        int L = 0;
        int R = rows.size()-1;

        while(L < R){
            ans += rows[R--] - rows[L++];
        }
        return ans;
    }
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rows;
        vector<int> cols;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j])continue;
                rows.push_back(i);
                cols.push_back(j);
            }
        }

        sort(cols.begin(),cols.end());
        
        return minDist(rows)+minDist(cols);
    }
};