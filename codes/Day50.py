from binarytree import build, Node
# Definition for a binary tree node.
# class Node:
#     def __init__(self, val=0, left=None, right=None):
#         self.value = val
#         self.left = left
#         self.right = right


def leaf(root, arr):
    if root:
        if not root.left and not root.right:
            arr.append(root.value)
        leaf(root.left, arr)
        leaf(root.right, arr)


def leafSimilar(root1: Node, root2: Node) -> bool:
    leafs1, leafs2 = [], []
    leaf(root1, leafs1)
    leaf(root2, leafs2)

    if (leafs1 == leafs2):
        return True

    return False


def main():
    nodes = input().split()
    nodes = [int(x) if x != "null" else None for x in nodes]
    nodes = build(nodes)
    root1 = nodes[0]
    nodes = input().split()
    nodes = [int(x) if x != "null" else None for x in nodes]
    nodes = build(nodes)
    root2 = nodes[0]

    print(leafSimilar(root1, root2))


if __name__ == "__main__":
    main()
