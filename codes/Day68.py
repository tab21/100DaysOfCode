from collections import deque
from binarytree import build, Node

# class Node:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def prune(self, root):
        if not root:
            return 0
        l = self.prune(root.left)
        r = self.prune(root.right)

        if l == 0:
            root.left = None

        if r == 0:
            root.right = None

        return root.val or r or l

    def pruneTree(self, root: Node) -> Node:
        if not root:
            return root

        r = self.prune(root)

        if r == 0:
            return None
        else:
            return root


def levelOrder(root: Node):
    if not root:
        return

    q = deque()
    q.append(root)
    while (q):
        level = []
        n = len(q)
        for i in range(n):
            curr = q.popleft()
            level.append(curr.val)
            if curr.left:
                q.append(curr.left)
            if curr.right:
                q.append(curr.right)
        print(level)


def main():
    nodes = input().split()
    nodes = [x if x != "null" else None for x in nodes]
    nodes = build(nodes)
    root = nodes[0]

    ans = Solution()
    resultRoot = ans.pruneTree(root)

    levelOrder(resultRoot)


if __name__ == "__main__":
    main()
