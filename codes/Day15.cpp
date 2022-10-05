
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n < 2)
    {
        return 0;
    }

    int pft = 0, mini = prices[0];

    for (int i = 1; i < n; i++)
    {
        pft = max(prices[i] - mini, pft);
        mini = min(mini, prices[i]);
    }

    return pft;
}
int main()
{
    // your code goes here

    int n;
    cin >> n;
    vector<int> p;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    cout << maxProfit(p);
    return 0;
}
