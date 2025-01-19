class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int rows = heightMap.size();
        int cols = heightMap[0].size();

        // Min-heap to store the boundary cells
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        // Visited matrix to mark processed cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Push all boundary cells into the heap
        for (int i = 0; i < rows; ++i) {
            for (int j : {0, cols - 1}) {
                minHeap.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < cols; ++j) {
            for (int i : {0, rows - 1}) {
                if (!visited[i][j]) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        // Directions for moving up, down, left, and right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int waterTrapped = 0;
        int maxBoundaryHeight = 0;

        // Process cells from the heap
        while (!minHeap.empty()) {
            auto [height, cell] = minHeap.top();
            minHeap.pop();

            int x = cell.first, y = cell.second;
            maxBoundaryHeight = max(maxBoundaryHeight, height);

            // Check all 4 neighbors
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                // Skip if out of bounds or already visited
                if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || visited[nx][ny]) continue;

                // Water trapped at this cell
                waterTrapped += max(0, maxBoundaryHeight - heightMap[nx][ny]);

                // Update the neighbor's height to the max of its height and maxBoundaryHeight
                minHeap.push({max(heightMap[nx][ny], maxBoundaryHeight), {nx, ny}});
                visited[nx][ny] = true;
            }
        }

        return waterTrapped;
    }
};