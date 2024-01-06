#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

/*
    leetcode 1235. Maximum Profit in Job Scheduling
    https://leetcode.com/problems/maximum-profit-in-job-scheduling

    Time complexity: O(nlogn)
    Space complexity: O(n)

*/

class Solution {
public:

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        using int3 = tuple<int,int,int>;
        using int2 = pair<int,int>;
        vector<int3> jobs;
        for(size_t i = 0; i < startTime.size();i++)jobs.emplace_back(startTime[i],endTime[i],profit[i]);
        sort(jobs.begin(),jobs.end());
        
        int ans = 0;
        
        priority_queue<int2,vector<int2>,greater<int2>> minHeap;
        
        for(size_t i = 0; i < jobs.size();i++){
            auto [start,end,profit] = jobs[i];

            while(!minHeap.empty() && start >= minHeap.top().first){
                ans = max(ans,minHeap.top().second);
                minHeap.pop();        
            }
            minHeap.push({end,profit+ans});
        }
        while(!minHeap.empty()){
            ans = max(ans,minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};