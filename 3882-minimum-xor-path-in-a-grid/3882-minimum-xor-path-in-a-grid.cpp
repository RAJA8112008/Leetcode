class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        const int X = 1024;

        vector<vector<bitset<X>>> dp(
            n, vector<bitset<X>>(m)
        );

        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0)
                    continue;

                int val = grid[i][j];

                if (i > 0) {
                    for (int x = 0; x < X; x++) {
                        if (dp[i - 1][j][x]) {
                            dp[i][j][x ^ val] = 1;
                        }
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < X; x++) {
                        if (dp[i][j - 1][x]) {
                            dp[i][j][x ^ val] = 1;
                        }
                    }
                }
            }
        }

        for (int x = 0; x < X; x++) {
            if (dp[n - 1][m - 1][x])
                return x;
        }

        return -1;
    }
};