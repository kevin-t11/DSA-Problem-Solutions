#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

/***********************************************************************************
 * Cycle detection in undirected graph
 * READ : slides rough work : Graph#4.pdf
 * ********************************************************************************/

unordered_map<int, list<int>> adj;
unordered_map<int, bool> visited;

void prepare_adjlist(int a, int b, bool direction)
{
    adj[a].push_back(b);
    if (direction == 0)
    {
        adj[b].push_back(a);
    }
}

bool IsCycleBFS(int src, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    // create a data structure for track the parent
    unordered_map<int, int> parent;

    // initially parent is -1;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // check all neighbours those are visited or not and push into the queue
        for (auto neighbour : adj[frontNode])
        {
            if (visited[neighbour] && neighbour != parent[frontNode])
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}
bool IsCycleDFS(int src, int parent, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    visited[src] = 1;

    for (auto neighbour : adj[src])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = IsCycleDFS(neighbour, src, adj, visited);
            if (cycleDetected)
                return true;
        }
        else if (neighbour != parent)
            return true;
    }
    return false;
}
string cycleDetection(unordered_map<int, list<int>> &adj, int &n, int &m)
{

    // to handle the disconnected components
    // unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // bool ans1 = IsCycleBFS(i, adj, visited);
            bool ans1 = IsCycleDFS(i, -1, adj, visited);
            if (ans1 == true)
            {
                return "Yes";
            }
        }
    }
    return "No";
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
        int u, v;
        cin >> u >> v;
        prepare_adjlist(u, v, 0);
    }
    string ans = cycleDetection(adj, n, m);
    cout << ans << endl;

    return 0;
}

// input :
// Enter a number of Nodes :
//  9
//  Enter a number of Edges :
//  8
//  1 2
//  2 3
//  4 5
//  5 6
//  5 7
//  6 8
//  7 8
//  8 9
