
#include <bits/stdc++.h>
using namespace std;
int numTrees(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        int j = 0;
        while (j < i)
        {
            dp[i] += dp[i - 1 - j] * dp[j];
            j++;
        }
    }
    return dp[n];
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    cout << numTrees(n);
    return 0;
}
