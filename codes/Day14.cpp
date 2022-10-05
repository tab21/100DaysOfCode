
#include <bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums)
{

    int n = nums.size();
    int left = 1;
    int right = 1;
    int product = nums[0];

    for (int i = 0; i < n; i++)
    {
        left *= nums[i];
        right *= nums[n - 1 - i];
        product = max({product, left, right});

        if (left == 0)
            left = 1;
        if (right == 0)
            right = 1;
    }

    return product;
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

    cout << maxProduct(nums);
    return 0;
}
