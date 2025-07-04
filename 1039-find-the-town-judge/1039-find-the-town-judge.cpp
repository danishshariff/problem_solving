class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> itrustyou(n + 1, 0); 

        for (auto& it : trust) {
            int a = it[0];
            int b = it[1];
            itrustyou[a]--; 
            itrustyou[b]++; 
        }

        for (int i = 1; i <= n; ++i) {
            if (itrustyou[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};
