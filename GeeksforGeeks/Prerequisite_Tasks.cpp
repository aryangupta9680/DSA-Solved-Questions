class Solution
{
public:
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
    {
        // create Adjacency List
        vector<int> adj[N];
        vector<int> InDeg(N, 0);

        for (int i = 0; i < P; i++)
        {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
            InDeg[prerequisites[i].first]++;
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

        int count = 0; // kitna size ka mera topological sort hoga

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

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

        // size == N (I can complete all task)
        return count == N;
    }
};