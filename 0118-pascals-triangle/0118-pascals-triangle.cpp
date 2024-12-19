class Solution {
public:
    vector<int> genrow(int row) {
        long long ans = 1;
        vector<int> ansrow;
        for (int col = 0; col <= row; col++) {
            ansrow.push_back(ans);
            ans = ans * (row - col) / (col + 1);
        }
        return ansrow;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            ans.push_back(genrow(i));
        }
        return ans;
    }
};
