class Solution {
public:
    int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind == 0) {
            return (amount % coins[0] == 0) ? amount / coins[0] : 1e9;
        }

        if (dp[ind][amount] != -1) return dp[ind][amount];

        int notPick = solve(ind - 1, amount, coins, dp);

        int pick = 1e9;
        if (coins[ind] <= amount)
            pick = 1 + solve(ind, amount - coins[ind], coins, dp);

        return dp[ind][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int res = solve(n - 1, amount, coins, dp);
        return (res >= 1e9) ? -1 : res;
    }
};