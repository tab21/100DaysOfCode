#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1e5);
    if (n == 1)
        return 0;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j <= min(n - 1, i + nums[i]); j++)
        {
            dp[j] = min(dp[j], dp[i] + 1);
            if (j == n - 1)
                return dp[n - 1];
        }
    }
    return dp[n - 1];
}
int main()
{
    // your code goes here
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << jump(nums);
    return 0;
}
