
// class Solution {
// public:
// int func(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& maze){
//      if(i < 0 || j < 0 || maze[i][j] == 1) return 0;
//     if(i<0 ||j<0) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(i==0&&j==0){
//         return 1;
//     }
  
//     int top=func(i-1,j,dp,maze);

//     int left=func(i,j-1,dp,maze);
//     return dp[i][j]=top+left;
// }
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();

//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return func(m-1,n-1,dp,obstacleGrid);
//     }
// };


//tab
class Solution {
public:
int mazeObstaclesUtil(int n, int m, vector<vector<int>> &maze, vector<vector<int>> &dp) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           if (maze[i][j] == 1) {
    dp[i][j] = 0;
    continue;
}
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = up + left;
        }
    }

    return dp[n - 1][m - 1];
}

 int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1)); 
    return mazeObstaclesUtil(m, n, obstacleGrid, dp); 
}
    };