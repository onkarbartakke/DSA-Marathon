#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

vector<vector<int>> ans;
bool issafe(int **arr, int x, int y, int n)
{
	int row, col;
	for (row = 0; row <= x; row++)
	{
		if (arr[row][y] == 1)
			return false;
	}

	row = x;
	col = y;
	while (row >= 0 && col >= 0)
	{
		if (arr[row][col] == 1)
			return false;

		row--;
		col--;
	}

	row = x;
	col = y;
	while (row >= 0 && col < n)
	{
		if (arr[row][col] == 1)
			return false;

		row--;
		col++;
	}

	return true;
}

bool nqueen(int **arr, int x, int n)
{
	int row, col;
	if (x >= n)
	{
		vector<int> v;
		int i, j;
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < n; i++)
			{
				if (arr[i][j] == 1)
				{
					v.push_back(i + 1);
				}
			}
		}

		ans.push_back(v);
		return true;
	}
	bool res = false;
	for (col = 0; col < n; col++)
	{
		if (issafe(arr, x, col, n))
		{
			arr[x][col] = 1;

			/*
			if(nqueen(arr,x+1,n))
			{
				return true;
			}
			*/

			res = nqueen(arr, x + 1, n) || res;

			arr[x][col] = 0; //backtracking
		}
	}
	return res;
}
int main()
{
	int n, i, j;
	cout << "Enter the size of sqare board\n";
	cin >> n;
	int **arr;
	arr = new int *[n];
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}

	nqueen(arr, 0, n);
	cout << "\n";

	/*
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/

	cout << "\n\n";
	for (i = 0; i < ans.size(); i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << ans[i][j] << " ";
		}

		cout << "\n";
	}
}

//

class Solution
{
	public:
	bool isSafe(int row, int col, int n, vector<string> &board)
	{
		int x = 0;
		int y = col;

		while (x <= row)
		{
			if (board[x][col] == 'Q')
				return false;

			x++;
		}

		x = row;
		y = col;

		while (x >= 0 && y >= 0)
		{
			if (board[x][y] == 'Q')
				return false;

			x--;
			y--;
		}

		x = row;
		y = col;

		while (x >= 0 && y < n)
		{
			if (board[x][y] == 'Q')
				return false;

			x--;
			y++;
		}

		return true;
	}

	void solve(int row, vector<string> &board, vector<vector<string>> &ans, int n)
	{
		if (row >= n)
		{
			ans.push_back(board);
			return;
		}

		for (int col = 0; col < n; col++)
		{
			if (isSafe(row, col, n, board))
			{
				board[row][col] = 'Q';

				solve(row + 1, board, ans, n);

				board[row][col] = '.';
			}
		}
	}
	vector<vector<string>> solveNQueens(int n)
	{

		vector<vector<string>> ans;
		string s(n, '.');
		vector<string> board(n, s);

		solve(0, board, ans, n);

		return ans;
	}
};