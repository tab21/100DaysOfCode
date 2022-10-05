#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int rob(vector<int> &nums)
{
    int row = nums.size();
    if (row == 1)
        return nums[0];
    if (row == 2)
        return max(nums[0], nums[1]);

    vector<int> dp(row + 1, 0);
    dp[row - 1] = nums[row - 1];
    dp[row - 2] = nums[row - 2];

    for (int i = row - 3; i >= 0; i--)
    {
        dp[i] = max({dp[i + 1], dp[i + 2] + nums[i], dp[i + 3] + nums[i]});
    }
    return dp[0];
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

    cout << rob(nums);

    return 0;
}
