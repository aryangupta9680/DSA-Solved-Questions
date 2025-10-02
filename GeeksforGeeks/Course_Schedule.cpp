class Solution
{
public:
    vector<int> findOrder(int N, vector<vector<int>> prerequisites)
    {
        int P = prerequisites.size();
        // create Adjacency List
        vector<int> adj[N];
        vector<int> InDeg(N, 0);

        for (int i = 0; i < P; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            InDeg[prerequisites[i][0]]++;
        }

        // Kahn's Algorithm
        // Indegree find karna hai (present above for loop)

        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (!InDeg[i])
            {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // look at the neighbour
            for (int j = 0; j < adj[node].size(); j++)
            {
                InDeg[adj[node][j]]--;
                if (!InDeg[adj[node][j]])
                {
                    q.push(adj[node][j]);
                }
            }
        }

        vector<int> temp;

        // size == N (I can complete all task)
        return ans.size() == N ? ans : temp;
    }
};