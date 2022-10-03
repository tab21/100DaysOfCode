# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class LinkedList:
    def __init__(self):
        self.head = None

    # insertion method for the linked list
    def insert(self, data):
        newNode = ListNode(data)
        if (self.head):
            current = self.head
            while (current.next):
                current = current.next
            current.next = newNode
        else:
            self.head = newNode


def addTwoNumbers(l1, l2):

    def makeEq(l1, l2):
        p1, p2 = l1, l2
        while (p1 or p2):
            if (not p1):
                dum = ListNode(0)
                dum.next = l1
                l1 = dum
            else:
                p1 = p1.next
            if (not p2):
                dum = ListNode(0)
                dum.next = l2
                l2 = dum
            else:
                p2 = p2.next

        return l1, l2

    if (not l1):
        return l2
    if (not l2):
        return l1

    l1, l2 = makeEq(l1, l2)

    carry = True

    while (carry):
        carry = False
        p1, p2 = l1, l2
        prev = None
        while (p1):
            k = p1.val + p2.val
            p1.val = k % 10
            p2.val = k//10
            carry = carry or p2.val
            prev = p2
            p1 = p1.next
            p2 = p2.next

        prev.next = ListNode(0)
        if (l2.val):
            dum = ListNode(0)
            dum.next = l1
            l1 = dum
        else:
            l2 = l2.next

    return l1


def makeLL():
    n = int(input())
    LL = LinkedList()

    el = input().split()

    for i in range(n):
        LL.insert(int(el[i]))

    return LL.head


def printLL(head):
    while (head):
        print(head.val, end="")
        head = head.next

    print("\n")


def main():
    l1 = makeLL()
    l2 = makeLL()

    ans = addTwoNumbers(l1, l2)
    printLL(ans)


if __name__ == "__main__":
    main()
