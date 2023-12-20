#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

/*
    Time Complexity: O(nlogn+mlog(n+m))
    Space Complexity: O(n +m)

*/


using food = pair<int,string>;

auto comp = [](food& a, food&b){
    return  a.first < b.first || (a.first == b.first && 
        a.second > b.second);};

class FoodRatings {
public:

    unordered_map<string,pair<int,string>> book;
    unordered_map<string,priority_queue<food,vector<food>,decltype(comp)>> kitchen;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int N = foods.size();
        for(int i = 0; i < N; i++){
            book[foods[i]] = {ratings[i],cuisines[i]};
            kitchen[cuisines[i]].push({ratings[i],foods[i]});
        } 
    }
    
    void changeRating(string food, int newRating) {
        book[food].first = newRating;
        kitchen[book[food].second].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        while(!kitchen[cuisine].empty()){
            auto [r,n] = kitchen[cuisine].top();
            if(book[n].first != r){
                kitchen[cuisine].pop();
                continue;
            }

            return n;
        }
        return "NDEF";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */