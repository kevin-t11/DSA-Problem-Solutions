#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

/******************************************************************
 * Read : Graph#8.pdf
 * ****************************************************************/

unordered_map<int, list<int>> adj;
unordered_map<int, bool> visited;
unordered_map<int, int> parent;
int cnt = 0;

void prepare_adjlist(int a, int b, bool direction)
{
    adj[a].push_back(b);
    if (direction == 0)
    {
        adj[b].push_back(a);
    }
}

vector<int> shortest_path(int s, int t, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, int> &parent)
{
    // do bfs
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : adj[frontNode])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
                q.push(neighbour);
            }
        }
    }

    vector<int> res;

    int currentNode = t;
    res.push_back(t);
    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        res.push_back(currentNode);
        cnt++;
        // cout << currentNode << " ";
    }
    return res;
}
int main()
{
    int n;
    cout << "Enter the no of nodes :";
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
    int src, dest;
    cout << "Enter the source :";
    cin >> src;
    cout << "Enter the destination :";
    cin >> dest;

    vector<int> ans;
    ans = shortest_path(src, dest, adj, visited, parent);

    reverse(ans.begin(), ans.end());

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Shortest path length : " << cnt;

    return 0;
}

// 0 1
// 0 3
// 1 2
// 3 4
// 3 7
// 4 5
// 4 6
// 4 7
// 5 6
// 6 7
