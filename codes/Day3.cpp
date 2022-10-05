
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int wiggleMaxLength(vector<int> &nums)
{
    int r = 1, l = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
            r = l + 1;
        else if (nums[i] < nums[i - 1])
            l = r + 1;
    }

    return max(r, l);
}
int main()
{
    // your code goes here
    int n;
    cin >> n; // size of inputs;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << wiggleMaxLength(nums);

    return 0;
}
