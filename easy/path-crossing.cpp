#include <string>
#include <set>

using namespace std;

// https://leetcode.com/problems/path-crossing/
/*
    Time: O(n) where n is the length of the path
    Space: O(n) where n is the length of the path
*/

class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        set<pair<int,int>> set;
        set.insert({x,y});

        for(char c : path ){
            if(c == 'N')x-=1;
            else if(c == 'S')x+=1;
            else if(c=='E')y+=1;
            else y-=1;

            if(set.find({x,y}) != set.end())return true;
            set.insert({x,y});
        }
        return false;
    }
};