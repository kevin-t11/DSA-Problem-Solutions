#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
#include <limits.h>

using namespace std;

/***************************************
 * Shortest path in weighted DAG
 * READ : graph#9.pdf
 * *************************************/

unordered_map<int, list<pair<int, int>>> adj;
unordered_map<int, bool> visited;

void prepare_adjlist(int a, int b, int weight)
{
    pair<int, int> p = make_pair(b, weight);
    adj[a].push_back(p);
}

void printAdj(unordered_map<int, list<pair<int, int>>> &adj)
{
    for (auto i : adj)
    {
        cout << i.first << "->";
        for (auto j : i.second)
        {
            cout << "(" << j.first << "," << j.second << "), ";
        }
        cout << endl;
    }
}

void dfs(int node, stack<int> &topo, unordered_map<int, bool> &visited)
{
    visited[node] = true;

    // check all adjacent node
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour.first])
        {
            dfs(neighbour.first, topo, visited);
        }
    }

    // jab wapas to stack me push kardo - topological sort wala logic
    topo.push(node);
}

void getShortestPath(int src, stack<int> &topo, vector<int> &dist, unordered_map<int, bool> &visited)
{
    dist[src] = 0; // bcz the distance from src to src is 0;

    while (!topo.empty())
    {
        int top = topo.top();
        topo.pop();

        if (dist[top] != INT_MAX)
        {
            for (auto neighbour : adj[top])
            {
                if ((dist[top] + neighbour.second) < dist[neighbour.first])
                    dist[neighbour.first] = (dist[top] + neighbour.second);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the no of node :";
    cin >> n;

    int m;
    cout << "Enter the no of edges :";
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        prepare_adjlist(u, v, w);
    }
    // printAdj(adj);

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // do dfs
            dfs(i, s, visited);
        }
    }

    int src;
    cout << "Enter the source value :";
    cin >> src;

    vector<int> dist(n);

    // now all dist are initially INFINITY
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    getShortestPath(src, s, dist, visited);

    for (auto i : dist)
    {
        cout << i << " ";
    }
    return 0;
}

// 0 1 5
// 0 2 3
// 1 2 2
// 1 3 6
// 2 3 7
// 2 4 4
// 2 5 2
// 3 4 -1
// 4 5 -2

// output is : INF, 0 2 6 5 3