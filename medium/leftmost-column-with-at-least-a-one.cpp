#include <vector>

using namespace std;

/*
    leeetcode: 1428 Leftmost Column with at Least a One

    Time: O(nlogm)
    Space: O(1)

*/


 // This is the BinaryMatrix's API interface.
 // You should not implement it, or speculate about its implementation
class BinaryMatrix {
   public:
     int get(int row, int col);
     vector<int> dimensions();
 };

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dims = binaryMatrix.dimensions();
        int m = dims[0];
        int ans = dims[1];

        for(int i = 0; i < m;i++){
            int L = 0,R = ans-1;
            while(L<=R){
                int mid = (L+R)/2;
                if(binaryMatrix.get(i,mid)){
                    ans = mid;
                    R = mid-1; 
                }else L = mid+1;
            }
        }
        return ans < dims[1] ? ans : -1;
    }
};