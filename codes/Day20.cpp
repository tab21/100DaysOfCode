#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *detectCycle(ListNode *head)
{

    unordered_set<ListNode *> s;

    if (head == NULL || head->next == head)
    {
        return head;
    }
    int c = 0;
    while (head)
    {
        if (s.find(head) == s.end())
        {
            s.insert(head);
        }
        else
        {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

ListNode *makeLL()
{
    int n;
    cin >> n;
    int num, c = 0;
    ListNode *head = new ListNode;
    ListNode *temp = new ListNode;
    cin >> num;
    head->val = num;
    for (int i = 2; i <= n; i++)
    {
        if (c == 0)
        {
            cin >> num;
            temp->val = num;
            head->next = temp;
            c++;
        }
        else
        {
            cin >> num;
            ListNode *temp1 = new ListNode;
            temp1->val = num;
            temp->next = temp1;
            temp = temp1;
        }
    }
    return head;
}

void makeCycle(ListNode *head)
{
    int pos;
    cin >> pos;
    if (pos == -1)
    {
        return;
    }
    ListNode *end = head;

    while (end && end->next)
    {
        end = end->next;
    }
    for (int i = 0; i < pos; i++)
    {
        head = head->next;
    }
    end->next = head;
}
int main()
{
    ListNode *head = makeLL();
    makeCycle(head);

    head = detectCycle(head);
    if (head == NULL)
    {
        cout << "No cycle" << endl;
    }
    else
    {
        cout << head->val << endl;
    }
}
