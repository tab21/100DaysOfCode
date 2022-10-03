#include <bits/stdc++.h>
using namespace std;

// definition of listnode
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeNodes(ListNode *head)
{
    ListNode *ptr = head->next, *curr = head->next;
    int res = 0;
    while (ptr)
    {
        if (ptr->val == 0)
        {
            curr->val = res;
            curr->next = ptr->next;
            curr = curr->next;
            res = 0;
        }
        else
        {
            res += ptr->val;
        }

        ptr = ptr->next;
    }

    return head->next;
}

ListNode *connectLL()
{
    int n;
    cin >> n;

    if (n <= 0)
    {
        return nullptr;
    }

    int el;
    cin >> el;
    ListNode *head = new ListNode(el);
    ListNode *tmp = head;

    for (int i = 1; i < n; i++)
    {
        cin >> el;
        ListNode *tmp2 = new ListNode(el);
        tmp->next = tmp2;
        tmp = tmp2;
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
    cout << endl;
}

int main()
{
    ListNode *head = connectLL();
    head = mergeNodes(head);
    displayLL(head);
    return 0;
}
