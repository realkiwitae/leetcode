#include <string>

using namespace std;

/*
    Time complexity O(n)
    Space complexity O(1)
*/

class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int z = 0, o = 0;
        for(char c : s){
            z += c == '0';
            o += c== '1';
        }
        int zeroes = 0, ones = 0;
        for(int i = 0; i < (int)s.size()-1;i++){
            zeroes += s[i]=='0';
            ones += s[i]=='1';
            ans = max(zeroes+o-ones,ans);
        }

        return ans;
    }
};