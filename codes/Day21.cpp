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

ListNode *swapPairs(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    ListNode *p1 = head;
    ListNode *p2 = head->next;
    ListNode *n = p2->next;
    p2->next = p1;
    p1->next = swapPairs(n);

    return p2;
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

void displayLL(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int main()
{
    ListNode *head = makeLL();
    ListNode *swap = swapPairs(head);

    displayLL(swap);

    return 0;
}
