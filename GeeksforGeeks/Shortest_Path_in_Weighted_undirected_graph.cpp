class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // adjacency list create karni hai
        // neighbour, weight
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }

        // Dijkstra Algorithm
        vector<bool> Explored(n + 1, 0);
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
        p.push({0, 1});
        dist[1] = 0;

        while (!p.empty())
        {
            int node = p.top().second;
            p.pop();

            if (Explored[node])
            {
                continue;
            }

            Explored[node] = 1;

            for (int j = 0; j < adj[node].size(); j++)
            {
                int neighbour = adj[node][j].first;
                int weight = adj[node][j].second;
                if (!Explored[neighbour] && dist[node] + weight < dist[neighbour])
                {
                    dist[neighbour] = dist[node] + weight;
                    p.push({dist[neighbour], neighbour});
                    parent[neighbour] = node; // line added
                }
            }
        }

        vector<int> path;

        // There are two cases here
        // case 1: I cannot reach my destination
        if (parent[n] == -1)
        {
            path.push_back(-1);
            return path;
        }

        // case 2: I will reach my destination
        int dest = n;
        while (dest != -1)
        {
            path.push_back(dest);
            dest = parent[dest];
        }

        path.push_back(dist[n]);
        reverse(path.begin(), path.end());

        return path;
    }
};