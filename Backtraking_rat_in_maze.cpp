// User function template for C++

class Solution{
    public:
    
    int dx[4] = {1,0,0,-1};
    int dy[4] = {0,-1,1,0};
    char direction[4] = {'D', 'L', 'R', 'U'};
    
    bool isSafe(int i, int j, int row, int col, vector<vector<bool>> &visited, vector<vector<int>> &m)
    {
        if((i >=0 && i<row ) && (j >=0 && j<col) && m[i][j] == 1 && visited[i][j] == false)
        {
            return true;
        }
        return false;
    }
    
    void solveMaze(int i, int j, int row, int col, vector<vector<bool>> &visited, vector<string> &path, string output,vector<vector<int>> &m)
    {
        if(i == row-1 && j == col-1)
        {
            path.push_back(output);
            return;
        }
        
        for(int k = 0; k < 4; k++)
        {
            int newx = i + dx[k];
            int newy = j + dy[k];
            char dir = direction[k];
            
            
            if(isSafe(newx, newy, row, col, visited, m))
            {
                visited[newx][newy] = true;
                solveMaze(newx, newy, row, col, visited, path, output+ dir, m);
                
                //backtrack
                visited[newx][newy] = false;
            }
        }
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        int row = n;
        int col = n;
        
        vector<string> path;
        string output = "";
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        
        if(m[0][0] == 0)
        {
            return path;
        }
        
        visited[0][0] = true;
        
        solveMaze(0, 0, row, col, visited, path, output, m);
        
        return path;
    }
};
