#include <iostream>
#include <vector>
using namespace std;

// Adjacency Matrix
// Undirected Unweighted graph
int main()
{
    int vertex, edges;
    cout << "Enter vertex: ";
    cin >> vertex;
    cout << "Enter edges: ";
    cin >> edges;

    vector<vector<bool>> adjMat(vertex, vector<bool>(vertex, 0));

    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
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




// Directed Unweighted graph
// int main()
// {
//     int vertex, edges;
//     cout << "Enter vertex: ";
//     cin >> vertex;
//     cout << "Enter edges: ";
//     cin >> edges;

//     vector<vector<bool>> adjMat(vertex, vector<bool>(vertex, 0));

//     int u, v;
//     for (int i = 0; i < edges; i++)
//     {
//         cin >> u >> v;
//         adjMat[u][v] = 1;
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