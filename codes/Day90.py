# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        c = 0

        def countTotalNodes(r):
            nonlocal c
            if r:
                c += 1
                countTotalNodes(r.next)

        countTotalNodes(head)
        c = c-n
        if c == 0:
            return head.next

        r = ListNode(123, head)
        while (c):
            r = r.next
            c -= 1

        r.next = r.next.next

        return head


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


def makeLL():
    LL = LinkedList()
    el = input().split()
    n = len(el)

    for i in range(n):
        LL.insert(int(el[i]))

    return LL.head


def main():
    head = makeLL()
    n = int(input())
    ans = Solution()
    result = ans.removeNthFromEnd(head, n)

    while result:
        print(f"{result.val} -> ", end="")
        result = result.next

    print("null")


if __name__ == "__main__":
    main()
