#include <iostream>
#include <vector>
using namespace std;

// Adjacency List
// Undirected Unweighted graph
int main()
{
    int vertex, edges;
    cout << "Enter vertex: ";
    cin >> vertex;
    cout << "Enter edges: ";
    cin >> edges;

    vector<int> adjList[vertex];
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Print the list
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}




// Directed Unweighted graph
// int main()
// {
//     int vertex, edges;
//     cout << "Enter vertex: ";
//     cin >> vertex;
//     cout << "Enter edges: ";
//     cin >> edges;

//     vector<int> adjList[vertex];
//     int u, v;
//     for (int i = 0; i < edges; i++)
//     {
//         cin >> u >> v;
//         adjList[u].push_back(v);
//     }

//     // Print the list
//     for (int i = 0; i < vertex; i++)
//     {
//         cout << i << " -> ";
//         for (int j = 0; j < adjList[i].size(); j++)
//         {
//             cout << adjList[i][j] << " ";
//         }

//         cout << endl;
//     }

//     return 0;
// }