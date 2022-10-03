#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int sr = 0, er = matrix.size() - 1, sc = 0, ec = matrix[0].size() - 1;
    while (sr <= er && sc <= ec)
    {
        for (int i = sc; i <= ec and (sr <= er && sc <= ec); i++)
        {
            res.push_back(matrix[sr][i]);
        }
        sr++;

        for (int i = sr; i <= er and (sr <= er && sc <= ec); i++)
        {
            res.push_back(matrix[i][ec]);
        }
        ec--;

        for (int i = ec; i >= sc and (sr <= er && sc <= ec); i--)
        {
            res.push_back(matrix[er][i]);
        }
        er--;

        for (int i = er; i >= sr and (sr <= er && sc <= ec); i--)
        {
            res.push_back(matrix[i][sc]);
        }
        sc++;
    }

    return res;
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

    vector<int> ans = spiralOrder(v);
    for (auto el : ans)
    {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}
