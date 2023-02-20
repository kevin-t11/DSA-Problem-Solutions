#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <unordered_map>

using namespace std;
/***********************************************************************************
 * Topological Sort for DAG using dfs
 * READ : slides rough work : Graph#6.pdf
 * ********************************************************************************/
unordered_map<int, list<int>> adj;
unordered_map<int, bool> visited;

void preapare_adjlist(int u, int v, bool direction)
{
    adj[u].push_back(v);
    if (direction == 0)
    {
        adj[v].push_back(u);
    }
}

void dfs(int node, stack<int> &topo)
{
    visited[node] = 1;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, topo);
        }
    }
    // imp
    topo.push(node);
}

int main()
{
    int n;
    cout << "Enter a number of Nodes :" << endl;
    cin >> n;

    int m;
    cout << "Enter a number of Edges :" << endl;
    cin >> m;

    // graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // prepare the adj list
        preapare_adjlist(u, v, 1);
    }

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, s);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
}