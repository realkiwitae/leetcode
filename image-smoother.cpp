#include <vector>

using namespace std;

/*
    Time Complexity: O(n*m)
    Space Complexity: O(n*m)

*/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> ans(m,vector<int>(n,0));

        for(int i = 0; i<m; i++){
            for(int j = 0; j <n ; j++){
                int c = 0;
                for(int a = max(0,i-1); a <= min(m-1,i+1);a++){
                    for(int b = max(0,j-1);b <= min(n-1,j+1);b++){
                        ans[i][j] += img[a][b];
                        c++;
                    }
                }
                ans[i][j] /= c;

            }
        }

        return ans;
    }
};