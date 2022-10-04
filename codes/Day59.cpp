#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
{

    int n = mat.size();
    int m = mat[0].size();

    map<int, priority_queue<int, vector<int>>> mp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mp[i - j].push(mat[i][j]);
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            mat[i][j] = mp[i - j].top();
            mp[i - j].pop();
        }
    }

    return mat;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> ans = diagonalSort(v);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
