#include <bits/stdc++.h>
using namespace std;
class MyCalendar
{
public:
    vector<vector<int>> cal;
    MyCalendar() {}

    bool book(int start, int end)
    {
        int n = cal.size();
        for (int i = 0; i < n; i++)
        {
            if (start >= cal[i][0] && end <= cal[i][1])
                return false;
            if (start < cal[i][1] && end >= cal[i][1])
                return false;
            if (end > cal[i][0] && end < cal[i][1])
                return false;
        }

        cal.push_back({start, end});
        return true;
    }
};

// intput
// ["MyCalendar", "book", "book", "book"]
// [[], [10, 20], [15, 25], [20, 30]]

int main()
{
    int n;
    cin >> n;

    vector<string> inputs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inputs[i];
    }

    vector<string> ans(n);
    MyCalendar *obj;

    for (int i = 0; i < n; i++)
    {
        if (inputs[i] == "MyCalendar")
        {
            obj = new MyCalendar();
            ans.push_back("null");
        }
        else
        {
            int st, en;
            cin >> st >> en;

            if (obj->book(st, en))
            {
                ans.push_back("true");
            }
            else
            {
                ans.push_back("false");
            }
        }
    }

    for (auto el : ans)
    {
        cout << el << " ";
    }
    cout << endl;
    return 0;
}
