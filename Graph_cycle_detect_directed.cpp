#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

/***********************************************************************************
 * Cycle detection in directed graph
 * READ : slides rough work : Graph#5.pdf also read Graph#6.pdf
 * ********************************************************************************/

unordered_map<int, list<int>> adj;
unordered_map<int, bool> visited;
unordered_map<int, bool> dfsvisited;

void prepare_adjlist(int a, int b, bool direction)
{
    adj[a].push_back(b);
    if (direction == 0)
    {
        adj[b].push_back(a);
    }
}

bool cycleDetectDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    dfsvisited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = cycleDetectDFS(neighbour, visited, dfsvisited, adj);
            if (cycleDetected)
                return true;
        }
        else if (dfsvisited[neighbour])
        {
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(int n, unordered_map<int, list<int>> &adj)
{
    // call dfs for all components
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cycleFound = cycleDetectDFS(i, visited, dfsvisited, adj);
            if (cycleFound)
                return true;
        }
    }
    return false;
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
        prepare_adjlist(u, v, 1);
    }
    bool ans = detectCycleInDirectedGraph(n, adj);
    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}

// input :
// Enter a number of Nodes :
//  8
//  Enter a number of Edges :
//  9
//  1 2
//  2 3
//  2 4
//  4 5
//  5 6
//  6 4
//  3 7
//  3 8
//  7 8

/*****************************************************************************************
 * Using Topological Sort and using bfs
 * ***************************************************************************************/
// #include <unordered_map>
// #include <list>
// #include <queue>

// bool isCyclic(vector<vector<int>> &edges, int v, int e)
// {
//     // create a adj list
//     unordered_map<int, list<int>> adj;

//     for (int i = 0; i < edges.size(); i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];

//         adj[u].push_back(v);
//     }

//     // find indegrees of all node
//     vector<int> indegree(v);
//     for (auto i : adj)
//     {
//         for (auto j : i.second)
//         {
//             indegree[j]++;
//         }
//     }

//     // 0th degree walo ko queue me push kardo
//     queue<int> q;
//     for (int i = 0; i < v; i++)
//     {
//         if (indegree[i] == 0)
//             q.push(i);
//     }

//     // do bfs
//     int cnt = 0;
//     while (!q.empty())
//     {
//         int frontNode = q.front();
//         q.pop();

//         // increment count
//         cnt++;

//         for (auto neighbour : adj[frontNode])
//         {
//             indegree[neighbour]--;
//             if (indegree[neighbour] == 0)
//                 q.push(neighbour);
//         }
//     }
//     if (cnt == v)
//     {
//         // means valid topological sort -> means DAG -> means No cycle
//         return false;
//     }
//     else
//         return true;
// }
