
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void help(vector<int> &cost, int i, vector<int> &dp)
{
    if (i >= cost.size())
    {
        return;
    }
    if (i < 2)
    {
        dp[i] = cost[i];
    }
    else
    {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    help(cost, i + 1, dp);
    return;
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n);
    help(cost, 0, dp);

    return min(dp[n - 1], dp[n - 2]);
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    cout << minCostClimbingStairs(c);

    return 0;
}
