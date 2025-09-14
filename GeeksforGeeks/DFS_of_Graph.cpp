class Solution
{
public:
    void DFSofGraph(int node, vector<vector<int>> &adj, vector<int> &ans, vector<bool> &visited)
    {
        visited[node] = 1;
        ans.push_back(node);

        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!visited[adj[node][j]])
            {
                DFSofGraph(adj[node][j], adj, ans, visited);
            }
        }
    }

    vector<int> dfs(vector<vector<int>> &adj)
    {
        int v = adj.size(); // number of vertices
        vector<bool> visited(v, 0);
        vector<int> ans;
        DFSofGraph(0, adj, ans, visited);
        return ans;
    }
};