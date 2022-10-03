#include <bits/stdc++.h>
using namespace std;

int minPartitions(string n)
{
    int res = INT_MIN;

    for (auto i : n)
    {
        res = max(i - '0', res);
    }

    return res;
}

int main()
{
    string n;
    cin >> n;
    cout << minPartitions(n) << endl;
    return 0;
}
