#include <bits/stdc++.h>
using namespace std;

int maxSumSubmatrix(vector<vector<int>> &matrix, int tar)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i + 1][j] = dp[i][j] + matrix[i][j];
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        for (int l = i + 1; l <= m; l++)
        {
            for (int j = 0; j < n; j++)
            {
                int val = 0;
                for (int k = j; k < n; k++)
                {
                    val += dp[l][k] - dp[i][k];

                    if (val < tar)
                    {
                        ans = max(ans, val);
                    }
                    else if (val == tar)
                    {
                        return tar;
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }
    int target;
    cin >> target;

    cout << maxSumSubmatrix(v, target) << endl;
    return 0;
}
