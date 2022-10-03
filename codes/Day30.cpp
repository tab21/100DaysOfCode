#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{

    while (stones.size() > 1)
    {
        sort(stones.begin(), stones.end());
        int n = stones.size();

        if (stones[n - 1] == stones[n - 2])
        {
            stones.pop_back();
            stones.pop_back();
        }
        else
        {
            stones[n - 2] = stones[n - 1] - stones[n - 2];
            stones.pop_back();
        }
    }

    if (stones.size())
    {
        return stones[0];
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i << n; i++)
    {
        cin >> v[i];
    }

    cout << lastStoneWeight(v) << endl;
    return 0;
}
