#include <vector>

using namespace std;

/*
    1. Find the rows and columns with only one 1.
    2. Check if the column of the row with only one 1 has only one 1.

    Time complexity: O(m*n)
    Space complexity: O(m+n)
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rows[m];
        vector<int> cols(n,0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n;j++){
                if(!mat[i][j])continue;
                rows[i].push_back(j);
                cols[j]++;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < m ; i++){
            if(rows[i].size() != 1)continue;
            if(cols[rows[i][0]] == 1)ans++;
        }

        return ans;
    }
};