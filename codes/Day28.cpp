#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string s, string t)
{
    vector<int> a(126), b(126);
    if (s.size() != t.size())
        return false;

    for (auto i : s)
    {
        a[(int)i]++;
    }
    for (auto i : t)
    {
        b[(int)i]++;
    }

    for (int i = 0; i < 126; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << isAnagram(s, t) << endl;
    return 0;
}
