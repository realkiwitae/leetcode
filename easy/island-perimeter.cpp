#include <queue>
#include <vector>

using namespace std;

/*
    463. Island Perimeter

    O(n*m) time and O(1) space
*/

class Solution {
public:

    size_t m,n;

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        queue<pair<int,int>> q;

        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(!grid[i][j])continue;
                q.push({i,j});
                grid[i][j] = 2;
                break;
            }
        }

        vector<pair<int,int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto [u,v] = q.front();
            q.pop();

            for(auto [x,y] : dirs){
                x+=u;
                y+=v;
                if(x < 0 || y < 0 || x >m-1 || y > n-1 || grid[x][y] == 0){
                    ans++;
                    continue;
                }
                if(grid[x][y]==1){
                    q.push({x,y});
                    grid[x][y] = 2;
                }
            }
        }

        return ans;
    }
};