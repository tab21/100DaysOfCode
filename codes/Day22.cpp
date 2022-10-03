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
void displayLL(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

ListNode *partition(ListNode *head, int x)
{
    ListNode *less = new ListNode(-123);
    less->next = head;
    head = less;

    while (less->next and less->next->val < x)
    {
        less = less->next;
    }

    ListNode *more = less;
    while (more and more->next)
    {
        if (more->next->val < x and more != less)
        {
            ListNode *tmp = more->next;
            more->next = more->next->next;
            tmp->next = less->next;
            less->next = tmp;
            less = less->next;
        }
        else
        {
            more = more->next;
        }
    }
    return head->next;
}
int main()
{
    ListNode *head = makeLL();
    int x;
    cin >> x;

    ListNode *part = partition(head, x);

    displayLL(part);

    return 0;
}
