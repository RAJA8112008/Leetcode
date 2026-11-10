
class Solution {
public:
    int solve(int i, int n, vector<int>& costs, vector<int>& dp) {

        // Base case
        if(i == n) return 0;

        // Memoization check
        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        // Try three jumps
        for(int step = 1; step <= 3; step++) {

            int j = i + step;

            if(j <= n) {

                int cost = costs[j - 1] + step * step;

                ans = min(ans, cost + solve(j, n, costs, dp));
            }
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n + 1, -1);

        return solve(0, n, costs, dp);
    }
};
