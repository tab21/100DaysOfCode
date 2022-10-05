#include <bits/stdc++.h>
using namespace std;
int getMaxLen(vector<int> &nums)
{

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));

    if (nums[0] > 0)
        dp[0][0]++;
    else if (nums[0] < 0)
        dp[0][1]++;

    int res = dp[0][0];

    for (int i = 1; i < n; ++i)
    {
        if (nums[i] != 0)
        {
            if (nums[i] > 0)
            {
                dp[i][0] = 1 + dp[i - 1][0];
                if (dp[i - 1][1])
                    dp[i][1] = 1 + dp[i - 1][1];
            }
            else
            {
                if (dp[i - 1][1])
                    dp[i][0] = dp[i - 1][1] + 1;

                dp[i][1] = dp[i - 1][0] + 1;
            }
        }

        res = max(res, dp[i][0]);
    }
    return res;
}
int main()
{
    // your code goes here

    int n;
    cin >> n;
    vector<int> p(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    cout << getMaxLen(p);
    return 0;
}
