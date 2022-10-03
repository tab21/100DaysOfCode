#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
    {
        return "0";
    }

    int n = num1.length(), m = num2.length();

    vector<int> res(n + m, 0);

    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            int no = (num1[i] - '0') * (num2[j] - '0');
            res[i + j] += (no + res[i + j + 1]) / 10;
            res[i + j + 1] = (no + res[i + j + 1]) % 10;
        }
    }

    string ans = "";
    int i = 0;
    while (i < res.size() && res[i] == 0)
    {
        i++;
    }

    while (i < res.size())
    {
        ans.push_back(res[i++] + '0');
    }
    return ans;
}

int main()
{
    string n1, n2;
    cin >> n1 >> n2;
    cout << multiply(n1, n2) << endl;
    return 0;
}
