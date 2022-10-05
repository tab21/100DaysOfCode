#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == nullptr)
    {
        return head;
    }

    ListNode *last = head, *curr = head;
    head = head->next;
    curr->next = NULL;
    while (head)
    {
        curr = head;
        head = head->next;
        curr->next = last;
        last = curr;
    }

    return curr;
}

int main()
{
    // your code goes here

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
    head = reverseList(head);

    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
