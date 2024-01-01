#include <vector>
#include <algorithm>

using namespace std;

/*
    leetcode 455. Assign Cookies
    https://leetcode.com/problems/assign-cookies/description/?envType=daily-question&envId=2024-01-01

    Time: O(nlogn + mlogm)
    Space: O(1)
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        int greed = g.size()-1;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int i = s.size()-1;i>=0; i--){
            while(greed>=0 && g[greed]>s[i])greed--;
            if(greed<0)return ans;
            greed--;
            ans++;
        }
        return ans;
    }
};