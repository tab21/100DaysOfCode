#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int maxSubArray(vector<int> &nums)
{

    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    int sum = nums[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        sum = max(dp[i], sum);
    }
    return sum;
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

    cout << maxSubArray(nums);
    return 0;
}
