/***********************************************************************************
 *
 *  Articulation point in a graph, Tarjan's Algorithm :
 * READ : slides rough work : Graph#14.pdf
 * also read Graph#13.pdf -> Bridge in graph -- similar to this..
 *
 * ********************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <limits.h>

using namespace std;

unordered_map<int, list<int>> adjList;
unordered_map<int, bool> vis;

// create adjancency list
void create_adj_list(int u, int v, unordered_map<int, list<int>> &adjList)
{

    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<int> &ap, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adjList)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for (auto nbr : adjList[node])
    {
        if (nbr == parent)
            continue;
        if (!vis[nbr])
        {
            dfs(nbr, node, timer, disc, low, ap, vis, adjList);

            // while returning then do this
            low[node] = min(low[node], low[nbr]);

            // check for AP or not
            if (low[nbr] >= disc[node] && parent != -1)
            {
                ap[node] = true;
            }
            child++;
        }
        else
        {
            // back edge case
            low[node] = min(low[node], disc[nbr]);
        }
    }

    // if node is root node and has > 1 child
    if (parent == -1 && child > 1)
    {
        ap[node] = true;
    }
}

int main()
{

    int n;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges :" << endl;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        create_adj_list(u, v, adjList);
    }

    vector<int> disc(n);
    vector<int> low(n);
    int parent = -1;
    int timer = 0;

    // ans vector
    vector<int> ap(n, 0);

    for (int i = 0; i < n; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    for (int node = 0; node < n; node++)
    {
        if (!vis[node])
        {
            dfs(node, parent, timer, disc, low, ap, vis, adjList);
        }
    }

    cout << "Articulation points are follows :" << endl;
    for (int i = 0; i < n; i++)
    {
        if (ap[i] == true)
            cout << i << " ";
    }
    cout << endl;
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