
#include <bits/stdc++.h>
using namespace std;
int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
{

    vector<vector<int>> dp(target + 1, vector<int>(n, INT_MAX));
    if (houses[0] == 0)
    {
        dp[1] = cost[0];
    }
    else
    {
        dp[1][houses[0] - 1] = 0;
    }

    for (int i = 1; i < m; i++)
    {
        for (int nei = target; nei > 0; nei--)
        {
            for (int col = 0; col < n; col++)
            {

                int min_cost = dp[nei][col];
                dp[nei][col] = INT_MAX;
                if (houses[i] != 0 && houses[i] != col + 1)
                    continue;

                int c = (houses[i] == 0) ? cost[i][col] : 0;
                if (min_cost != INT_MAX)
                {
                    min_cost += c;
                }

                for (int diff_col = 0; diff_col < n; diff_col++)
                {
                    if (col == diff_col)
                        continue;

                    int curr = dp[nei - 1][diff_col];
                    if (curr != INT_MAX)
                    {
                        curr += c;
                    }

                    min_cost = min(min_cost, curr);
                }

                dp[nei][col] = min_cost;
            }
        }
    }

    int ans = INT_MAX;
    for (int color = 0; color < n; color++)
    {
        ans = min(ans, dp[target][color]);
    }

    return (ans < INT_MAX ? ans : -1);
}

int main()
{
    // your code goes here

    int n, m, target;
    cin >> n >> m >> target;

    vector<int> houses(m);
    vector<vector<int>> cost(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        cin >> houses[i];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    return 0;
}
