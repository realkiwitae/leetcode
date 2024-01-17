#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
    leetcode: 1207. Unique Number of Occurrences

    Time: O(n)
    Space: O(n)

*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        unordered_set<int> set;
        for(int i : arr){
            map[i]++;
        }
        for(auto it :map)set.insert(it.second);
        return set.size() == map.size();
    }
};