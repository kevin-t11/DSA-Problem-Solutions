#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <limits.h>
using namespace std;

unordered_map<int, list<pair<int, int>>> adjList;

void prepare_adj_list(unordered_map<int, list<pair<int, int>>> &adjList, int n, int m)
{
    int u, v, w;
    cin >> u >> v >> w;

    adjList[u].push_back(make_pair(v, w));
    adjList[v].push_back(make_pair(u, w));
}

vector<pair<pair<int, int>, int>> calculate_PrimMST(int n, int m, unordered_map<int, list<pair<int, int>>> &adjList)
{
    vector<pair<pair<int, int>, int>> result;
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parents(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parents[i] = -1;
    }

    key[1] = 0;
    parents[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;
        for (int j = 1; j <= n; j++)
        {
            if (mst[j] == false && mini > key[j])
            {
                u = j;
                mini = key[j];
            }
        }

        mst[u] = true;

        for (auto neighbour : adjList[u])
        {
            int v = neighbour.first;
            int w = neighbour.second;
            if (mst[v] == false && w < key[v])
            {
                parents[v] = u;
                key[v] = w;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parents[i], i}, key[i]});
    }
    return result;
}

void print(vector<pair<pair<int, int>, int>> &ans)
{
    int cost = 0;
    cout << endl;
    for (auto i : ans)
    {
        cout << i.first.first << "-" << i.first.second << " " << i.second << endl;
        cost += i.second;
    }
    cout << endl;
    cout << "Total Minimum cost is : " << cost << endl;
}

void solve()
{
    int n;
    cout << "Enter number of Vertices : " << endl;
    cin >> n;
    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;
    for (int i = 1; i <= m; i++)
        prepare_adj_list(adjList, m, n);

    vector<pair<pair<int, int>, int>> ans;
    ans = calculate_PrimMST(n, m, adjList);

    print(ans);
}

int main()
{
    solve();
    return 0;
}

// 4 5 1
// 1 5 2
// 2 4 2
// 4 6 2
// 2 6 3
// 3 5 3
// 1 3 4
// 5 6 4
// 1 2 5
// 1 4 6