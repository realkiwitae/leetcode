#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int id = 0;
        vector<bool> cities(200,true);
        vector<string> names(200,"");
        unordered_map<string,int> book;
        for(vector<string>& path :paths){
            if(book.find(path[0])==book.end()){
                book[path[0]] = id++;
                names[book[path[0]]] = path[0];
            }
            cities[book[path[0]]] = false;
            if(book.find(path[1])==book.end()){
                book[path[1]] = id++;
                names[book[path[1]]] = path[1];
            }   
        }

        for(int i = 0; i < 200;i++){
            if(names[i] == "")continue;
            if(!cities[i])continue;
            return names[i];
        }

        return "NOT FOUND";
    }
};