
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

static bool change(const vector<int> &a, const vector<int> &b)
{
    return a[1] > b[1];
}

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{

    sort(boxTypes.begin(), boxTypes.end(), change);

    int i = 0, units = 0;
    while (i < boxTypes.size() && truckSize)
    {

        if (truckSize == 0)
        {
            break;
        }
        else
        {
            if (truckSize - boxTypes[i][0] >= 0)
            {
                units += boxTypes[i][1] * boxTypes[i][0];
                truckSize -= boxTypes[i][0];
            }
            else
                while (truckSize && boxTypes[i][0] > 0)
                {
                    units += boxTypes[i][1];
                    truckSize--;
                    boxTypes[i][0]--;
                }
        }
        i++;
    }

    return units;
}

int main()
{
    // your code goes here
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(2, 0));
    ;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }

    int truckSize;
    cin >> truckSize;

    cout << maximumUnits(a, truckSize);

    return 0;
}
