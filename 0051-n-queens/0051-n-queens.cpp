#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;

    void solve(int row, int n, vector<string>& board, vector<int>& cols, vector<int>& d1, vector<int>& d2) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || d1[row + col] || d2[row - col + n - 1]) continue;

            board[row][col] = 'Q';
            cols[col] = d1[row + col] = d2[row - col + n - 1] = 1;

            solve(row + 1, n, board, cols, d1, d2);

            board[row][col] = '.';
            cols[col] = d1[row + col] = d2[row - col + n - 1] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<string> board(n, string(n, '.'));
        vector<int> cols(n, 0), d1(2 * n, 0), d2(2 * n, 0);
        solve(0, n, board, cols, d1, d2);
        return result;
    }
};

