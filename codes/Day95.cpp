#include <bits/stdc++.h>
using namespace std;

int minCost(string colors, vector<int> &neededTime)
{
    int time = 0;
    int curr = 0;
    for (int i = 0; i < colors.size(); i++)
    {
        if (i > 0 and colors[i] != colors[i - 1])
        {
            curr = 0;
        }
        time += min(curr, neededTime[i]);
        curr = max(curr, neededTime[i]);
    }

    return time;
}

int main()
{
    string color;
    cin >> color;
    int n = color.size();

    vector<int> neededTime(n);
    for (int i = 0; i < n; i++)
    {
        cin >> neededTime[i];
    }

    cout << minCost(color, neededTime) << endl;

    return 0;
}
