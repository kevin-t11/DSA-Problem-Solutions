#include <iostream>
const int N = 1e3 + 10; // bcz maximum size...
int graph[N][N];

using namespace std;
int main()
{
    int n, m; // n-Verteces, m-Edges
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // create an undireted graph
        graph[u][v] = 1; // means that for u to v weight is 1;
        graph[v][u] = 1;
    }

    return 0;
}