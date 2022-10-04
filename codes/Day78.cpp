#include <bits/stdc++.h>
using namespace std;

int maximumScore(vector<int> &nums, vector<int> &multipliers)
{

    int m = multipliers.size();
    int n = nums.size();
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

    for (int o = m - 1; o >= 0; o--)
    {
        for (int l = o; l >= 0; l--)
        {
            int left = multipliers[o] * nums[l] + dp[o + 1][l + 1];
            int right = multipliers[o] * nums[n - 1 - (o - l)] + dp[o + 1][l];
            dp[o][l] = max(left, right);
        }
    }

    return dp[0][0];
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cin >> n;
    vector<int> mult(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mult[i];
    }

    cout << maximumScore(nums, mult) << endl;
    return 0;
}
