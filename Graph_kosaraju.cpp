/***********************************************************************************
 *
 *           Kosaraju's Algo : Count or find strongly connected components
 *           READ : slides rough work : Graph#15.pdf
 *
 * ********************************************************************************/

#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

void prepare_adjList(int u, int v, unordered_map<int, list<int>> &adjList)
{
    adjList[u].push_back(v);
}

void dfs(int node, stack<int> &s, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adjList)
{
    vis[node] = true;

    for (auto nbr : adjList[node])
    {
        if (!vis[nbr])
            dfs(nbr, s, vis, adjList);
    }

    // while returning then push into the stack
    s.push(node);
}

void revdfs(int node, stack<int> &s, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &transpose)
{
    vis[node] = true;

    // dfs
    for (auto nbr : transpose[node])
    {
        if (!vis[nbr])
            revdfs(nbr, s, vis, transpose);
    }
}

int main()
{
    int n;
    cout << "Enter the number of nodes :" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges :" << endl;
    cin >> m;

    unordered_map<int, list<int>> adjList;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        prepare_adjList(u, v, adjList);
    }

    // step 1 : find topo sort
    stack<int> s;
    unordered_map<int, bool> vis;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, s, vis, adjList);
        }
    }

    // step 2:create transpose of a graph
    unordered_map<int, list<int>> transpose;

    for (int i = 0; i < n; i++)
    {
        // we have to reintialized the visited array because (dfs) would be called the visited was updated.
        vis[i] = 0;
        for (auto nbr : adjList[i]) // keep in mind
        {
            transpose[nbr].push_back(i);
        }
    }

    // dfs call using above ordering
    int count = 0;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();

        if (!vis[top])
        {
            count++;
            revdfs(top, s, vis, transpose);
        }
    }

    cout << "No of Strongly Connected Components are :" << count << endl;

    return 0;
}

// input :
//  Enter the number of nodes :
//  5
//  Enter the number of edges :
//  5
//  0 1
//  1 2
//  2 0
//  1 3
//  3 4

/* graph example

        1
       / \
      /   \
     /     \
    0-------2------3
                   |
                   |
                   |
                   4

*/