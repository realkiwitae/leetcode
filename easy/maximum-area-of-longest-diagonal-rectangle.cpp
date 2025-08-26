class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        int maxdiag2 = 0;
        for (const auto& dim : dimensions) {
            int diag2 = dim[0] * dim[0] + dim[1] * dim[1];
            if (diag2 >= maxdiag2) {
                maxdiag2 = diag2;
                maxArea = max(maxArea, dim[0] * dim[1]);
            }
        }
        return maxArea;
    }
};