#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    int i = 0;
    bool neg = false;
    int n = s.size();
    while (i < n and s[i] == ' ')
    {
        i++;
    }
    if (i < n and s[i] == '-')
    {
        neg = true;
        i++;
    }
    else if (i < n and s[i] == '+')
    {
        i++;
    }

    long number = 0;

    while (i < n and isdigit(s[i]))
    {
        long t = (number * 10) + (s[i] - '0');

        if (t > INT_MAX)
        {
            if (neg)
            {
                return INT_MIN;
            }
            return INT_MAX;
        }

        number = t;
        i++;
    }

    if (neg)
    {
        return -number;
    }
    return number;
}

int main()
{
    string number;
    cin >> number;
    cout << myAtoi(number) << endl;

    return 0;
}
