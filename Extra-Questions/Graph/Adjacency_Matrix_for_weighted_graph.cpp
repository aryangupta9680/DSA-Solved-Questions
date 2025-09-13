#include <iostream>
#include <vector>
using namespace std;

// Adjacency Matrix
// Undirected Weighted graph
int main()
{
    int vertex, edges;
    cout << "Enter vertex: ";
    cin >> vertex;
    cout << "Enter edges: ";
    cin >> edges;

    vector<vector<int>> adjMat(vertex, vector<int>(vertex, 0));

    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;
        adjMat[u][v] = weight;
        adjMat[v][u] = weight;
    }

    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout << adjMat[i][j] << " ";
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

//     vector<vector<int>> adjMat(vertex, vector<int>(vertex, 0));

//     int u, v, weight;
//     for (int i = 0; i < edges; i++)
//     {
//         cin >> u >> v >> weight;
//         adjMat[u][v] = weight;
//     }

//     for (int i = 0; i < vertex; i++)
//     {
//         for (int j = 0; j < vertex; j++)
//         {
//             cout << adjMat[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }