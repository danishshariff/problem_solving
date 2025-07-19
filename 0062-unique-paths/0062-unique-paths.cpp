// class Solution {
// public:
// int func(int i,int j,vector<vector<int>>& dp){
//     if(i<0 ||j<0) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(i==0&&j==0){
//         return 1;
//     }
  
//     int top=func(i-1,j,dp);

//     int left=func(i,j-1,dp);
//     return dp[i][j]=top+left;
// }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return func(m-1,n-1,dp);
//     }
// };

//tab

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         dp[0][0]=1;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0&&j==0) continue;
//                 else{
//                     int top=0;
//                     int left=0;
//                     if(i>0)  top=dp[i-1][j];

//                    if(j>0)  left=dp[i][j-1];
//                     dp[i][j]= top+left;
//                 }
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };

//space

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
        vector<int> cur(n,0);
            for(int j=0;j<n;j++){
                if(i==0&&j==0) cur[j]=1;
                else{
                    int top=0;
                    int left=0;
                    if(i>0)  top=prev[j];

                   if(j>0)  left=cur[j-1];
                    cur[j]= top+left;
                }
            }
            prev=cur;
        }
        return prev[n-1];
    }
};