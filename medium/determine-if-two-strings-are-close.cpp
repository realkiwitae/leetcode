#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
    leetcode: 1657 Determine if Two Strings Are Close

    Time: O(n)
    Space: O(1)

*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())return 0;

        vector<int> occ1(26,0),occ2(26,0);

        for(char c : word1)occ1[c-'a']++;
        for(char c : word2){
            occ2[c-'a']++;
            if(!occ1[c-'a'])return false;
        }

        sort(occ1.begin(),occ1.end());
        sort(occ2.begin(),occ2.end());

        return occ1 == occ2;

    }
};