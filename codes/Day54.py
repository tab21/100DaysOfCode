from cairo import SolidPattern


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def rev(self, root):

        curr = root
        prev = None

        while curr:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp

        return prev

    def cut(self, root):

        slow, fast = root, root

        while (fast and fast.next):
            slow = slow.next
            fast = fast.next.next

        root_second = self.rev(slow)
        return root, root_second

    def compare(self, root1, root2):
        if not root1 and not root2:
            return True
        if not root1 and not root2.next:
            return True

        if not root2 and not root1.next:
            return True

        if root1.val == root2.val:
            return self.compare(root1.next, root2.next)
        else:
            return False

    def isPalindrome(self, head: ListNode) -> bool:
        root1, root2 = self.cut(head)
        return self.compare(root1, root2)


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
    n = int(input())
    LL = LinkedList()

    el = input().split()

    for i in range(n):
        LL.insert(int(el[i]))

    return LL.head


def main():
    head = makeLL()
    ans = Solution()
    print(ans.isPalindrome(head))


if __name__ == "__main__":
    main()
