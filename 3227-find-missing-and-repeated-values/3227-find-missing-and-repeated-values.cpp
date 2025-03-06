#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> count;
        int n = grid.size();
        int repeated = -1, missing = -1;

      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count[grid[i][j]]++;
            }
        }

      
        for (int num = 1; num <= n * n; num++) {
            if (count[num] == 2) repeated = num;
            if (count[num] == 0) missing = num;
        }

        return {repeated, missing};
    }
};
