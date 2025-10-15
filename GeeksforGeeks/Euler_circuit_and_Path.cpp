class Solution
{
public:
    void DFS(int node, vector<int> adj[], vector<bool> &visited)
    {
        visited[node] = 1;

        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!visited[adj[node][j]])
            {
                DFS(adj[node][j], adj, visited);
            }
        }
    }

    int isEulerCircuit(int V, vector<int> adj[])
    {
        // Euler Circuit
        // calculate the degree of each node
        // all node should have even degree
        // all non-zero degree node should be connected

        // Euler Path
        // calculate the degree of each node
        // zero or two node can have odd degree and remaining have even degree
        // all non-zero degree node should be connected

        vector<int> Deg(V, 0);
        int Odd_Deg = 0; // number of nodes having odd degree
        for (int i = 0; i < V; i++)
        {
            Deg[i] = adj[i].size();
            if (Deg[i] % 2)
            {
                Odd_Deg++;
            }
        }

        if (Odd_Deg != 2 && Odd_Deg != 0)
        {
            return 0;
        }

        vector<bool> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (Deg[i])
            {
                DFS(i, adj, visited);
                break;
            }
        }

        // if non-zero degree node is still not visited, return 0;
        // Degree zero hai to usko ignore karna hai (koi edge nahi hai
        for (int i = 0; i < V; i++)
        {
            if (Deg[i] && !visited[i])
            {
                return 0;
            }
        }

        // Eulerian circuit, return 2
        // Eulerian path, return 1

        if (Odd_Deg == 0)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
};