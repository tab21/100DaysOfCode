#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j)
{
    int n = grid.size(), m = grid[0].size();

    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0' || grid[i][j] == '2')
    {
        return;
    }

    grid[i][j] = '2';
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                res++;
                dfs(grid, i, j);
            }
        }
    }

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    cout << numIslands(v) << endl;
    return 0;
}
