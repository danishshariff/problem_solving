// class Solution {
// public:
//     int func(int i, int j, vector<vector<int>>& grid,vector<vector<int>> & dp) {
//         int m = grid.size();
//         int n = grid[0].size();

//         if (j < 0 || j >= n) return 1e9;

//         if (i == m - 1) return grid[i][j];
//         if(dp[i][j]!=-1) return dp[i][j];
//         int down = grid[i][j] + func(i + 1, j, grid,dp);
//         int ld = grid[i][j] + func(i + 1, j - 1, grid,dp);
//         int rd = grid[i][j] + func(i + 1, j + 1, grid,dp);

//         return dp[i][j]=min(down, min(ld, rd));
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n=matrix[0].size();
//         int minSum = INT_MAX;
//         vector<vector<int>> dp(m,vector<int>(n,-1));

//         for (int j = 0; j < m; j++) {
//             minSum = min(minSum, func(0, j, matrix,dp));
//         }

//         return minSum;
//     }
// }

//tab

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[m - 1][j] = matrix[m - 1][j];
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int down = matrix[i][j] + dp[i + 1][j];
                int ld = (j > 0) ? matrix[i][j] + dp[i + 1][j - 1] : 1e9;
                int rd = (j < n - 1) ? matrix[i][j] + dp[i + 1][j + 1] : 1e9;

                dp[i][j] = min({down, ld, rd});
            }
        }

        // Find minimum in the first row
        int minSum = INT_MAX;
        for (int j = 0; j < n; j++) {
            minSum = min(minSum, dp[0][j]);
        }

        return minSum;
    }
};
