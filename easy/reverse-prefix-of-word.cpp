#include <algorithm> 
#include <string>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        std::size_t found = word.find_first_of(ch);
        if(found!=string::npos) std::reverse(word.begin(),word.begin()+found+1);

        return word;
    }
};