// 1160. Find Words That Can Be Formed by Characters
// difficulty: easy
// website: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

// O(N) time complexity, N is the number of characters in words
// O(1) space complexity


#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int book[26];
        memset(book,0,sizeof(book));
        for(char c : chars)book[c-'a']++;
    
        int ans = 0;

        for(string word : words){
            int test[26];
            memset(test,0,sizeof(test)); 
            for(char c : word)test[c-'a']++;
            bool b = true;
            for(int i = 0; i < 26;i++){
                if(test[i]>book[i]){
                    b=false;
                    break;
                }
            }
            if(b)ans += word.size();
        }

        return ans;
    }
};