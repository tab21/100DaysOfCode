
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
{
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());

    int maxih = 0, maxiv = 0;

    for (int i = 0; i < horizontalCuts.size(); i++)
    {
        if (i == 0)
        {
            maxih = horizontalCuts[i];
        }
        if (i == horizontalCuts.size() - 1)
        {
            maxih = max(h - horizontalCuts[i], maxih);
        }
        if (i != 0)
        {
            int com = horizontalCuts[i] - horizontalCuts[i - 1];
            maxih = max(com, maxih);
        }
    }
    cout << endl;

    for (int i = 0; i < verticalCuts.size(); i++)
    {
        if (i == 0)
        {
            maxiv = verticalCuts[i];
        }
        if (i == verticalCuts.size() - 1)
        {
            maxiv = max(maxiv, w - verticalCuts[i]);
        }
        if (i != 0)
        {
            int com = verticalCuts[i] - verticalCuts[i - 1];
            maxiv = max(maxiv, com);
        }
    }

    return ((long)maxih * maxiv) % ((int)pow(10, 9) + 7);
}
int main()
{
    // your code goes here

    int h, w;
    cin >> h; //"enter height : "
    cin >> w; //"enter weight : "

    int n, m;
    cin >> n; //"enter number of horizontal cuts : "
    cin >> m; //"enter number of vertical cuts : "

    vector<int> hcuts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> hcuts[i];
    }

    vector<int> vcuts(m);
    for (int i = 0; i < m; i++)
    {
        cin >> vcuts[i];
    }

    cout << "Ans : " << maxArea(h, w, hcuts, vcuts);
    return 0;
}
