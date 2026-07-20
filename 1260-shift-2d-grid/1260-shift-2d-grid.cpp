class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int row = grid.size();
        int col = grid[0].size();

        vector<int> store;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                store.push_back(grid[i][j]);
            }
        }

        int n = row * col;
        k %= n;

        reverse(store.begin(), store.end());
        reverse(store.begin(), store.begin() + k);
        reverse(store.begin() + k, store.end());

        int idx = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                grid[i][j] = store[idx++];
            }
        }

        return grid;
    }
};