#include <iostream>
#include <vector>
using namespace std;

// Adjacency List
// Undirected Weighted graph
int main()
{
    int vertex, edges;
    cout << "Enter vertex: ";
    cin >> vertex;
    cout << "Enter edges: ";
    cin >> edges;

    vector<pair<int, int>> adjList[vertex];
    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }

    // Print the list
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j].first << " " << adjList[i][j].second << " ";
        }

        cout << endl;
    }

    return 0;
}




// Directed Weighted graph
// int main()
// {
//     int vertex, edges;
//     cout << "Enter vertex: ";
//     cin >> vertex;
//     cout << "Enter edges: ";
//     cin >> edges;

//     vector<pair<int, int>> adjList[vertex];
//     int u, v, weight;
//     for (int i = 0; i < edges; i++)
//     {
//         cin >> u >> v >> weight;
//         adjList[u].push_back(make_pair(v, weight));
//     }

//     // Print the list
//     for (int i = 0; i < vertex; i++)
//     {
//         cout << i << " -> ";
//         for (int j = 0; j < adjList[i].size(); j++)
//         {
//             cout << adjList[i][j].first << " " << adjList[i][j].second << " ";
//         }

//         cout << endl;
//     }

//     return 0;
// }