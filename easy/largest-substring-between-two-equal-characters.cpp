#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

/*
    leetcode: 1624. Largest Substring Between Two Equal Characters
    https://leetcode.com/problems/largest-substring-between-two-equal-characters/
    space: O(n)
    time: O(n)
*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> book;
        int ans = -1;
        for(size_t i = 0; i < s.size();i++){
            if(book.find(s[i]) != book.end()){
                ans = max(ans,(int)i - book[s[i]]-1);
            }else{
                book[s[i]] = i;
            }
            
        }
        return ans;
    }
};