//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isSafe(int node, int color[], bool graph[101][101], int n, int clr)
    {
        for(int nbr = 0; nbr<n; nbr++)
        {
            if(nbr != node && graph[nbr][node] == 1 && color[nbr] == clr)  // graph[nbr][node] == 1 means there is an edge
                return false;
        }
        return true;
    }
    
    bool solve(int node, bool graph[101][101], int color[], int m, int n)
    {
        //reached to the last node
        if(node == n)
            return true;
        
        for(int clr = 1; clr <= m; clr++)
        {
            if(isSafe(node, color, graph, n, clr))
            {
                //consider the color of particular node
                color[node] = clr;
                
                if(solve(node+1, graph, color, m, n))
                    return true;
                    
                //backtracking
                color[node] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        int color[n] = {0};
        int strtnode = 0;
        if(solve(strtnode, graph, color, m, n) == true)
            return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends