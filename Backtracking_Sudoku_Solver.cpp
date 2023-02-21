class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char c){
        for(int i = 0; i < board.size(); i++){
            //check for row
            if(board[row][i] == c)
                return false;
            //check for column
            if(board[i][col] == c)
                return false;
            //check for 3*3 matrix
            if(board[(3*(row/3) + i/3)][(3*(col/3) + i%3)] == c)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board)
    {
        int n = board.size();

        for(int row = 0; row<n; row++){
            for(int col = 0; col<n; col++){
                //check for empty cell
                if(board[row][col] == '.'){
                    for(char c ='1'; c<='9'; c++){
                        if(isSafe(row, col, board, c)){
                            board[row][col] = c;
                            if(solve(board) == true) 
                                return true;
                            else{
                                //backtracking
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
    }
};