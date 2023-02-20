#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

using namespace std;

unordered_map<int, list<int>> adj;
unordered_map<int, bool> visited;

// cteate a adj list
void addEdge(int u, int v, bool direction)
{

    // creation a edge from u to v
    adj[u].push_back(v);

    if (direction == 0)
    {
        adj[v].push_back(u);
    }
}

// bfs function
void bfs(int node, vector<int> &ans)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        // cout << frontNode << " ";
        q.pop();

        // store frontNode into ans
        ans.push_back(frontNode);

        // traverse all node neighbours of frontNode
        for (auto neighbour : adj[frontNode])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
            }
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

    // graph g;

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

    vector<int> ans;
    bfs(2, ans);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}