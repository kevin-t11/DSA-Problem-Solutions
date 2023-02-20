#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

using namespace std;

unordered_map<int, list<int>> adj;
unordered_map<int, bool> visited;
vector<int> ans;

// create a adj list
void addEdge(int u, int v, bool direction)
{

    // creation a edge from u to v
    adj[u].push_back(v);

    if (direction == 0)
    {
        adj[v].push_back(u);
    }
}

// dfs function
void dfs(int node)
{
    // mark as visited
    visited[node] = true;

    ans.push_back(node);
    // cout << node << " ";

    // Recursive call for each connected node(means neighbours)
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour);
        }
    }
}
int main()
{

    int n;
    cout << "Enter a number of Nodes :" << endl;
    cin >> n;

    int m;
    cout << "Enter a number of Edges :" << endl;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // prepare the adj list
        addEdge(u, v, 0);
    }
    // input :
    // Enter a number of Nodes :
    // 4
    //  Enter a number of Edges :
    // 6
    // 0 1
    // 0 2
    // 1 2
    // 2 0
    // 2 3
    // 3 3

    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         dfs(i);
    //     }
    // }

    dfs(2);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}