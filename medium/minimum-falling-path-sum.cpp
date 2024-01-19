#include <vector>
#include <algorithm>

using namespace std;

/*
    leetcode.com/problems/minimum-falling-path-sum

    Time: O(n^2)
    Space: O(1)
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 1; i < m ; i ++){
            for(int j = 0; j < n ; j++){
                int a = j>0 ? matrix[i-1][j-1] : 1e9;
                int b = j<n-1? matrix[i-1][j+1] :1e9;
                matrix[i][j] += min({a,b,matrix[i-1][j]});
            }
        }


        return *min_element(matrix[m-1].begin(),matrix[m-1].end());
    }
};