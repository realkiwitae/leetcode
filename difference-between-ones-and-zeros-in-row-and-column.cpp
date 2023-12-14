#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rows(m,0);
        vector<int> cols(n,0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j <n; j++){
                if(!grid[i][j])continue;
                rows[i]++;
                cols[j]++;
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j <n; j++){
                grid[i][j] = 2*rows[i] - m + 2*cols[j] - n;
            }
        }
        return grid;
    }
};