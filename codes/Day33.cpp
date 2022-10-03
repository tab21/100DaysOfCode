
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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *f = head, *s = head;

    while (n)
    {
        f = f->next;
        n--;
    }

    if (!f)
        return head->next;

    while (f->next)
    {
        f = f->next;
        s = s->next;
    }

    s->next = s->next->next;

    return head;
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
    int n;
    cin >> n;
    head = removeNthFromEnd(head, n);
    displayLL(head);

    return 0;
}
