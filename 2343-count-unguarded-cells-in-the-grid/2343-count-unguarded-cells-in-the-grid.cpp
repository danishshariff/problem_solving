class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // Initialize grid

        // Mark walls and guards on the grid
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = -1; // Wall
        }
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 1; // Guard
        }

        // Mark cells guarded by guards
        for (auto& guard : guards) {
            int x = guard[0], y = guard[1];
            
            // Move in all four directions
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto& dir : directions) {
                int nx = x, ny = y;
                while (true) {
                    nx += dir.first;
                    ny += dir.second;

                    // Check boundaries or if the cell is blocked
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == -1 || grid[nx][ny] == 1) {
                        break;
                    }

                    // Mark cell as guarded if it's unoccupied
                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 2; // 2 indicates guarded
                    }
                }
            }
        }

        // Count unguarded cells
        int unguardedCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) { // Unoccupied and unguarded
                    unguardedCount++;
                }
            }
        }

        return unguardedCount;
    }
};
