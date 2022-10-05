
#include <bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> mp, tp;
    if (s.size() != t.size())
    {
        return false;
    }

    for (int i = 0; i < t.size(); i++)
    {
        if (mp.find(s[i]) == mp.end() && tp.find(t[i]) == tp.end())
        {
            mp[s[i]] = t[i];
            tp[t[i]] = s[i];
        }
        else
        {
            if (mp[s[i]] != t[i])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    // your code goes here
    string s, t;
    cin >> s >> t;
    cout << isIsomorphic(s, t);
    return 0;
}
