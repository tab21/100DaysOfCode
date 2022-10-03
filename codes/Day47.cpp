#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s)
{
    int a[26] = {0};

    for (int i = 0; i < s.size(); i++)
    {
        a[s[i] - 'a']++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (a[s[i] - 'a'] == 1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string s;
    cin >> s;
    cout << firstUniqChar(s) << endl;
    return 0;
}
