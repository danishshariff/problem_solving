// class Solution {
// public:
//     int func(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
//         int m = triangle.size();
//         if (i == m - 1) return triangle[i][j]; 
//         if (dp[i][j] != -1) return dp[i][j];

//         int down = triangle[i][j] + func(i + 1, j, triangle, dp);
//         int diag = triangle[i][j] + func(i + 1, j + 1, triangle, dp);

//         return dp[i][j] = min(down, diag);
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m = triangle.size();
//         vector<vector<int>> dp(m, vector<int>(m, -1));
//         return func(0, 0, triangle, dp);
//     }
// };


//tab

// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int m = triangle.size();
//         vector<vector<int>> dp(m, vector<int>(m, -1));
//         for(int i=0;i<m;i++){
//             dp[m-1][i]=triangle[m-1][i];
//         }
//         for(int i=m-2;i>=0;i--){
//             for(int j=i;j>=0;j--){
//              int down = triangle[i][j] + dp[i+1][j];
//              int diag = triangle[i][j] + dp[i+1][j+1];
//               dp[i][j] = min(down, diag);
//             }
//         }
//         return dp[0][0];
//     }
// };


//space


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int>prev(m,0);
        for(int i=0;i<m;i++){
           prev[i]=triangle[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            vector<int> cur(m,0);
            for(int j=i;j>=0;j--){
             int down = triangle[i][j] + prev[j];
             int diag = triangle[i][j] + prev[j+1];
            cur[j] = min(down, diag);
            }
            prev=cur;
        }
        return prev[0];
    }
};
