
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int candy(vector<int> &ratings)
{

    int n = ratings.size();
    vector<int> can(n);

    for (int i = 0; i < n; i++)
    {
        can[i] = 1;
        if (i == 0)
        {
            continue;
        }
        if (ratings[i] > ratings[i - 1])
        {
            can[i] = can[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i + 1] < ratings[i])
        {
            can[i] = max(can[i], can[i + 1] + 1);
        }
    }

    return accumulate(can.begin(), can.end(), 0);
}
int main()
{
    // your code goes here
    int n;
    cin >> n; // no. of input elements

    vector<int> ratings(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ratings[i];
    }

    cout << candy(ratings);

    return 0;
}
