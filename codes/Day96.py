from binarytree import build, Node

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def leafsum(self, root, currsum, tarsum):
        if not root:
            return
        currsum += root.val
        if not root.left and not root.right:
            if currsum == tarsum:
                return True
            else:
                return False
        return self.leafsum(root.left, currsum, tarsum) or self.leafsum(root.right, currsum, tarsum)

    def hasPathSum(self, root: Node, targetSum: int) -> bool:
        return self.leafsum(root, 0, targetSum)


def main():
    nodes = input().split()
    nodes = [int(x) if x != "null" else None for x in nodes]
    nodes = build(nodes)
    root = nodes[0]
    targetSum = int(input())
    ans = Solution()

    print(ans.hasPathSum(root, targetSum))


if __name__ == "__main__":
    main()
