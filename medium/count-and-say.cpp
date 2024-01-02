#include <string>

using namespace std;

/*
    leetcode 38. Count and Say
    https://leetcode.com/problems/count-and-say/

    Time: O(n)
    Space: O(1)

*/

class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        while(--n){
            string say = "";
            int L = 0,R=0;
            while(L < curr.length()){
                while(R < curr.length() && curr[R] == curr[L])R++;
                say.append(to_string(R-L)+curr[L]);
                L = R;
            }
            curr = say;
        }
        return curr;
    }
};