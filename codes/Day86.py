from binarytree import build, Node
# Definition for a binary tree node.
# class Node:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def pathSum(self, root: Node, targetSum: int) -> list[list[int]]:
        res = []

        def paths(r, s, a):
            if not r:
                return

            paths(r.left, s+[r.val], a+r.val)
            paths(r.right, s+[r.val], a+r.val)

            if not r.left and not r.right:
                if a+r.val == targetSum:
                    res.append(s+[r.val])

        paths(root, [], 0)

        return res


def main():
    nodes = input().split()
    nodes = [x if x != "null" else None for x in nodes]
    nodes = build(nodes)
    root = nodes[0]

    target = int(input())

    ans = Solution()
    result = ans.pathSum(root, target)

    for row in result:
        print(row)


if __name__ == "__main__":
    main()
