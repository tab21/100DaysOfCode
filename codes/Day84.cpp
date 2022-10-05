#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    int n = s.size();
    int l = 0;
    for (int i = 0; i <= n; i++)
    {
        if (s[i] == ' ' || i == n)
        {
            int e = i - 1;
            while (l < e)
            {
                char tmp = s[l];
                s[l] = s[e];
                s[e] = tmp;
                l++;
                e--;
            }
            l = i + 1;
        }
    }

    return s;
}

int main()
{
    string s;
    getline(cin, s);

    cout << reverseWords(s) << endl;
    return 0;
}
