// User function Template for C++

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(V, 1e8); // 1e8 = 100000000
        dist[src] = 0;
        int e = edges.size();

        for (int i = 0; i < V - 1; i++)
        {
            // Relax all the edges (V-1) times
            bool flag = 0;

            for (int j = 0; j < e; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int weight = edges[j][2];

                if (dist[u] == 1e8)
                {
                    continue;
                }

                if (dist[u] + weight < dist[v])
                {
                    flag = 1;
                    dist[v] = dist[u] + weight;
                }
            }

            if (!flag)
            {
                return dist;
            }
        }

        // to deduct the cycle
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if (dist[u] == 1e8)
            {
                continue;
            }

            if (dist[u] + weight < dist[v])
            {
                // cycle deducted
                vector<int> ans;
                ans.push_back(-1);
                return ans;
            }
        }

        return dist;
    }
};
