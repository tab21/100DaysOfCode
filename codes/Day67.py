from collections import deque

# Definition for a Node.


class Node:
    def __init__(self, val=None):
        self.val = val
        self.children = []

    def addChild(self, child):
        self.children.append(child)


class Solution:
    def levelOrder(self, root: Node) -> list[list[int]]:
        res = []
        q = deque()
        if not root:
            return res
        q.append(root)

        while (q):
            level = []

            n = len(q)

            for i in range(n):
                p = q.popleft()
                for c in p.children:
                    q.append(c)
                level.append(p.val)

            res.append(level)

        return res


def buildTree():
    elements = input().split()
    elements = [int(x) if x != "null" else None for x in elements]
    q = deque()
    root = None
    parent = None
    for el in elements:
        if el == None:
            parent = q.popleft()
        else:
            if root == None and parent == None:
                root = parent = Node(el)
                q.append(parent)
            else:
                child = Node(el)
                parent.addChild(child)
                q.append(child)

    return root


def main():
    root = buildTree()
    ans = Solution()
    result = ans.levelOrder(root)

    for row in result:
        print(row)


if __name__ == "__main__":
    main()
