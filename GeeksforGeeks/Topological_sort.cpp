// Method 1: Using DFS
class Solution
{
public:
    void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s)
    {
        visited[node] = 1;

        // look at its neighbour one by one
        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!visited[adj[node][j]])
            {
                DFS(adj[node][j], adj, visited, s);
            }
        }

        s.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // using DFS
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<bool> visited(V, 0);
        stack<int> s;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS(i, adj, visited, s);
            }
        }

        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};





// Method 2: using Kahn's Algorithm
class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<int> ans;
        vector<int> InDegree(V, 0); // store the indegree of every node

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                InDegree[adj[i][j]]++;
            }
        }

        // push all the node of zero indegree into queue
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (!InDegree[i])
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // neighbour ki indegree ko decrease karna hai 1 se
            for (int j = 0; j < adj[node].size(); j++)
            {
                InDegree[adj[node][j]]--;
                if (InDegree[adj[node][j]] == 0)
                {
                    q.push(adj[node][j]);
                }
            }
        }

        return ans;
    }
};