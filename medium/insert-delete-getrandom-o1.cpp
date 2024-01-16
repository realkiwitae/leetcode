#include <unordered_set>
#include <iterator>

using namespace std;

/**
    leetcode: 380. Insert Delete GetRandom O(1)

    Time: O(1)
    Space: O(n)

*/

class RandomizedSet {
public:
    unordered_set<int> set;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(set.count(val))return false;
        set.insert(val);
        return true;        
    }
    
    bool remove(int val) {
        if(!set.count(val))return false;
        set.erase(val);
        return true;
    }
    
    int getRandom() {
        int index = random() % set.size();
        auto iter = set.begin();
        advance(iter, index);
        return *iter;
    }
};