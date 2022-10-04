from binarytree import build, Node

# class Node:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def pseudoPalindromicPaths(self, root: Node) -> int:
        c = 0

        def count(node, path):
            nonlocal c
            if node:
                path = path ^ (1 << node.val)
                if not node.left and not node.right:
                    if path & (path - 1) == 0:
                        c += 1
                else:
                    count(node.left, path)
                    count(node.right, path)

        count(root, 0)
        return c


def main():
    nodes = input().split()
    nodes = [x if x != "null" else None for x in nodes]
    nodes = build(nodes)
    root = nodes[0]

    ans = Solution()
    print(ans.pseudoPalindromicPaths(root))


if __name__ == "__main__":
    main()
