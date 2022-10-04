from binarytree import build, Node
from collections import deque

# Definition for a binary tree node.
# class Node:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def verticalTraversal(self, root: Node) -> list[list[int]]:
        ans = []
        mini = 0
        maxi = 0

        q = deque()
        q.append((0, root, 0))

        while (q):
            n = len(q)

            for i in range(n):
                row, p, col = q.popleft()
                ans.append((row, col, p.val))

                if (col > maxi):
                    maxi = col
                elif (col < mini):
                    mini = col

                if (p.left):
                    q.append((row+1, p.left, col-1))
                if (p.right):
                    q.append((row+1, p.right, col+1))

        ans = sorted(ans)

        res_right = [[] for _ in range(maxi+1)]
        res_left = [[] for _ in range(-1*mini)]

        for row, col, val in ans:
            if (col >= 0):
                res_right[col].append(val)
            else:
                res_left[col].append(val)

        return res_left+res_right


def main():
    nodes = input().split()
    nodes = [int(x) if x != "null" else None for x in nodes]
    nodes = build(nodes)
    root = nodes[0]

    ans = Solution()
    ans = ans.verticalTraversal(root)
    for row in ans:
        print(row)


if __name__ == "__main__":
    main()
