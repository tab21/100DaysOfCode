from binarytree import build, Node
from collections import deque

# Definition for a binary tree node.
# class Node:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:

    def addOneRow(self, root: Node, val: int, depth: int) -> Node:

        def adding(r, currdepth):
            if not r or currdepth >= depth:
                return

            if currdepth+1 == depth:
                tmpl = r.left
                tmpr = r.right
                r.left = Node(val, tmpl)
                r.right = Node(val, None, tmpr)

            adding(r.left, currdepth+1)
            adding(r.right, currdepth+1)

        if depth == 1:
            res = Node(val, root)
            return res

        adding(root, 1)
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

    value = int(input())
    depth = int(input())

    ans = Solution()
    levelOrder(ans.addOneRow(root, value, depth))


if __name__ == "__main__":
    main()
