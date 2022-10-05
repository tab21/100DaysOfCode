
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return nums.size();
    }
    sort(nums.begin(), nums.end());

    int l = 0, r = 0;
    int res = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - 1 == nums[i - 1])
        {
            r++;
        }
        else if (nums[i] == nums[i - 1])
        {
            l++;
            r++;
        }
        else
        {
            res = max(res, r - l + 1);
            l = r;
        }
    }
    res = max(res, r - l + 1);
    return res;
}
int main()
{
    // your code goes here

    int n;
    cin >> n; // number of inputs

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << longestConsecutive(nums);

    return 0;
}
