class Solution {
public:

    vector<pair<int,int>> directions = {
        {-1,-1},
        {1,-1},
        {-1,1},
        {1,1}
    };

    int minBishopMoves(vector<int>& source, vector<int>& target) {

        int sr = source[0] - 1;
        int sc = source[1] - 1;

        int tr = target[0] - 1;
        int tc = target[1] - 1;

        // Already at target
        if (sr == tr && sc == tc)
            return 0;

        vector<vector<bool>> visited(8, vector<bool>(8, false));

        queue<pair<int,int>> q;

        q.push({sr, sc});
        visited[sr][sc] = true;

        int step = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                auto p = q.front();
                q.pop();

                // Explore 4 diagonal directions
                for (auto dir : directions) {

                    int nr = p.first + dir.first;
                    int nc = p.second + dir.second;

                    // Keep moving along the diagonal
                    while (nr >= 0 && nr < 8 &&
                           nc >= 0 && nc < 8) {

                        // Target found
                        if (nr == tr && nc == tc)
                            return step + 1;

                        if (!visited[nr][nc]) {
                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }

                        nr += dir.first;
                        nc += dir.second;
                    }
                }
            }

            step++;
        }

        return -1;
    }
};