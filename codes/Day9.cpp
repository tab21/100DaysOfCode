
#include <bits/stdc++.h>
using namespace std;
int tribonacci(int n)
{
    int t[n + 3];
    t[0] = 0;
    t[1] = 1;
    t[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        t[i] = t[i - 1] + t[i - 2] + t[i - 3];
    }

    return t[n];
}

int fib(int n)
{
    vector<int> dp(n + 2, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
int main()
{
    // your code goes here
    int n;
    cin >> n;
    cout << "fibonacci : " << fib(n) << endl;
    cout << "tribonacci : " << tribonacci(n) << endl;

    return 0;
}
