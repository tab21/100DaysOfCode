#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> mp{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]] < mp[s[i + 1]])
            res -= mp[s[i]];
        else
            res += mp[s[i]];
    }
    return res;
}

int main()
{
    string roman;
    cin >> roman;

    cout << romanToInt(roman) << endl;
    return 0;
}
