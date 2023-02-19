#include <bits/stdc++.h> 

unordered_map<int, bool> rowCheck, upperDiag, lowerDiag;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
	vector<int> temp;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			temp.push_back(board[i][j]);
		}
	}

	ans.push_back(temp);
	
}


bool isSafe_bruteforce(int row, int col, vector<vector<int>> &board, int n)
{

	//brute force approch

	// 3 case we have to handle
	int x = row;
	int y = col;
	
	//check for row - placing is safe on row or not
	while(y >= 0)
	{
		if(board[x][y] == 1)
			return false;
		y--;
	}

	//check for upper diagonal
	//restore the value of x and y
	x = row;
	y = col;
	while(x < n && y >= 0)
	{
		if(board[x][y] == 1)
			return false;
		x++;
		y--;
	}
	
	//check for lower diagonal
	x = row;
	y = col;
	while(x >= 0 && y >= 0)
	{
		if(board[x][y] == 1)
			return false;
		x--;	
		y--;
	}

	return true;

}

bool isSafe_optimal(int row, int col, vector<vector<int>> &board, int n, unordered_map<int, bool> &rowCheck, unordered_map<int, bool> &upperDiag, unordered_map<int, bool> &lowerDiag)
{
	if(rowCheck[row]== true || upperDiag[row+col]== true || lowerDiag[n-1+col-row]== true)
		return false;
	
	return true;
}

void markTrue(int row, int col, int n)
{
	rowCheck[row] = true;
	upperDiag[row+col] = true;
	lowerDiag[n-1+col-row] = true;
}

void markFalse(int row, int col, int n)
{
	rowCheck[row] = false;
	upperDiag[row+col] = false;
	lowerDiag[n-1+col-row] = false;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
	//basecase
	if(col == n)
	{
		addSolution(board, ans, n);
		return;
	}

	//solve 1 case and rest portion will take cared by recursion
	for(int row = 0; row < n; row++)
	{
		//if placing queen is safe or not
		if(isSafe_optimal(row, col, board, n, rowCheck, upperDiag, lowerDiag))
		{
			board[row][col] = 1; // mark visited board
			markTrue(row, col, n); // mark true mapping
			
			solve(col+1, ans, board, n);

			// Backtracking
			board[row][col] = 0;
			markFalse(row, col, n);
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<vector<int>> ans;

	solve(0, ans, board, n);
	return ans;
}