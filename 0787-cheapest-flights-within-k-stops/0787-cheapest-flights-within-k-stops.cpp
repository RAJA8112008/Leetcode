class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // create adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;

        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        // dist[i] = minimum cost to reach i
        vector<int> dist(n, INT_MAX);

        // queue -> {node, cost}
        queue<pair<int, int>> q;

        q.push({src, 0});
        dist[src] = 0;

        int stops = 0;

        while (!q.empty() && stops <= k) {

            int size = q.size();

            // copy of dist for this level
            vector<int> temp = dist;

            while (size--) {

                int node = q.front().first;
                int cost = q.front().second;
                q.pop();

                // traverse neighbours
                for (auto nbr : adj[node]) {

                    int nextNode = nbr.first;
                    int price = nbr.second;

                    if (cost + price < temp[nextNode]) {

                        temp[nextNode] = cost + price;

                        q.push({nextNode, temp[nextNode]});
                    }
                }
            }

            dist = temp;
            stops++;
        }

        if (dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};