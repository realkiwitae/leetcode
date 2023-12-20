#include <string>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
    
        for(int i = 0 ; i < num.size()-2;i++){
            if(num[i]==num[i+1] && num[i]==num[i+2] && (ans.empty()||ans[0]<num[i])){
                ans = string(3,num[i]);
            }
        }
        return ans;
    }
};