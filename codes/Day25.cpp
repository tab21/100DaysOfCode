#include <bits/stdc++.h>
using namespace std;
int left(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1, mid;
    int ans = -1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;

        if (nums[mid] == target)
        {
            ans = mid;
            r = mid - 1;
        }
        else if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return ans;
}
int right(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1, mid;
    int ans = -1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;

        if (nums[mid] == target)
        {
            ans = mid;
            l = mid + 1;
        }
        else if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return ans;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    return {left(nums, target), right(nums, target)};
}
int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int target;
    cin >> target;

    vector<int> ans = searchRange(v, target);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
