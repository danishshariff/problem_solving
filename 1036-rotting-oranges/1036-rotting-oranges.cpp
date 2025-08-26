

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int freshOranges = 0;

        // Initialize the queue with all initially rotten oranges and count fresh oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else if(grid[i][j] == 1) {
                    freshOranges++;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        int tm = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // BFS traversal
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    grid[nrow][ncol] = 2;  // Mark the orange as rotten in the grid
                    freshOranges--;  // Decrease the count of fresh oranges
                    tm = max(tm, t + 1);
                }
            }
        }

        // If there are still fresh oranges left, return -1
        return freshOranges == 0 ? tm : -1;
    }
};