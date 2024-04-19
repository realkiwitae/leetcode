#include <queue>
#include <vector>

using namespace std;

/*
    200. Number of Islands

    O(n*m) time and O(1) space

*/


class Solution {
public:

    using int2 = pair<int,int>;
    vector<int2> dirs{{0,1},{0,-1},{1,0},{-1,0}};
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j]=='0')continue;

                ans++;

                grid[i][j] = '0';
                
                queue<int2> q;
                q.push({i,j});
                while(!q.empty()){
                    auto [i,j] = q.front();
                    q.pop();
                    for(auto [x,y] : dirs){
                        x+=i;
                        y+=j;

                        if(x<0||y<0||x>m-1||y>n-1||grid[x][y]=='0')continue;

                        q.push({x,y});
                        grid[x][y] = '0';
                    }   
                }
            }
        }
        return ans;
    }
};