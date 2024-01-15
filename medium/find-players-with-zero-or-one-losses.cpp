#include <vector>
#include <algorithm>

using namespace std;

/*
    leetcode: 2225. Find Players With Zero or One Losses

    Time: O(n)
    Space: O(m) m range of input ids

*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = 1e5+1;
        vector<int> loss(n,-1);
        for(auto m : matches){
            int w = m[0],l = m[1];
            if(loss[w]==-1)loss[w]=0;
            if(loss[l]==-1)loss[l]=1;
            else loss[l]++;
        }
        vector<vector<int>> ans = {{},{}};
        for(int i = 0; i < n;i++){
            if(loss[i]==-1 || loss[i]>1)continue;
            ans[loss[i]].push_back(i);
        }
        return ans;
    }
};