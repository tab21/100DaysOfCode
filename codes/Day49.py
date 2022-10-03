from binarytree import build, Node

# Definition for a binary tree node.
# class Node:
#     def __init__(self, val=0, left=None, right=None):
#         self.value = val
#         self.left = left
#         self.right = right


def findTarget(root, k) -> bool:
    s = set()

    def findingTarget(root, target):
        nonlocal s
        if root:
            if target - root.value in s:
                return True
            s.add(root.value)
            return findingTarget(root.left, target) or findingTarget(root.right, target)

        return False

    return findingTarget(root, k)


def main():
    nodes = input().split()
    nodes = [int(x) if x != "null" else None for x in nodes]
    nodes = build(nodes)
    root = nodes[0]
    target = int(input())
    print(findTarget(root, target))


if __name__ == "__main__":
    main()
