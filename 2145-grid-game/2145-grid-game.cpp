class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long topSum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long bottomSum = 0;
        long long result = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            topSum -= grid[0][i];
            result = min(result, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }

        return result;
    }
};
