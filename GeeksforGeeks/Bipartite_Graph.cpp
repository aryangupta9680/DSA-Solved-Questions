// Method 1: Using BFS
class Solution
{
public:
    bool isBipartite(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V, -1);
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                q.push(i);
                color[i] = 0;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (int j = 0; j < adj[node].size(); j++)
                    {
                        // color not assigned to them
                        if (color[adj[node][j]] == -1)
                        {
                            color[adj[node][j]] = (color[node] + 1) % 2;
                            q.push(adj[node][j]);
                        }

                        // color is already assigned
                        else
                        {
                            if (color[node] == color[adj[node][j]])
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};







// Method 2: Using DFS
class Solution
{
public:
    bool checkBip(int node, vector<vector<int>> &adj, vector<int> &color)
    {
        // look at each neighbour
        for (int j = 0; j < adj[node].size(); j++)
        {
            // color is not assigned to the neighbour
            if (color[adj[node][j]] == -1)
            {
                color[adj[node][j]] = (color[node] + 1) % 2;

                if (!checkBip(adj[node][j], adj, color))
                {
                    return false;
                }
            }

            // color is assigned to the neighbour
            else
            {
                if (color[node] == color[adj[node][j]])
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1) // not assigned
            {
                color[i] = 0;
                if (!checkBip(i, adj, color))
                {
                    return false;
                }
            }
        }

        return true;
    }
};