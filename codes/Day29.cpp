#include <bits/stdc++.h>
using namespace std;

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{

    int n = words.size();
    int m = pattern.size();

    vector<string> res;

    for (int i = 0; i < n; i++)
    {
        if (m != words[i].size())
        {
            continue;
        }

        map<char, char> mp;
        set<char> st;

        int j;
        for (j = 0; j < m; j++)
        {
            if (mp[words[i][j]])
            {
                if (mp[words[i][j]] == pattern[j])
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            else if (st.find(pattern[j]) != st.end())
            {
                break;
            }
            else
            {
                mp[words[i][j]] = pattern[j];
                st.insert(pattern[j]);
            }
        }

        if (j == m)
        {
            res.push_back(words[i]);
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    string pattern;
    cin >> pattern;

    vector<string> ans = findAndReplacePattern(words, pattern);

    for (auto el : ans)
    {
        cout << el << " ";
    }
    cout << endl;
    return 0;
}
