#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
    leetcode 2125. Number of Laser Beams in a Bank
    time: O(n*m)
    space: O(1)
*/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int L = 0;
        int lc = std::count(bank[L].begin(), bank[L].end(), '1');
        while(L<m && !lc){L++;lc = L<m?std::count(bank[L].begin(), bank[L].end(), '1'):0;}
        int R = L;
        int rc = 0;
        int ans = 0;
        while(L < m){
            while(R < m && !rc){R++; rc = R<m?std::count(bank[R].begin(), bank[R].end(), '1'):0;}
            if(R<m)ans+=rc*lc;
            lc = rc;
            L = R;
            rc = 0;
        }
        return ans;
    }
};