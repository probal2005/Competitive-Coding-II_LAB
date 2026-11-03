class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor(self, root, p, q):
        if root is None or root is p or root is q:
            return root

        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        if left is not None and right is not None:
            return root

        return left if left is not None else right


def main():
    """
              3
             / \
            5   1
           / \ / \
          6  2 0  8
            / \
           7   4
    """

    root = TreeNode(3)

    root.left = TreeNode(5)
    root.right = TreeNode(1)

    root.left.left = TreeNode(6)
    root.left.right = TreeNode(2)

    root.right.left = TreeNode(0)
    root.right.right = TreeNode(8)

    root.left.right.left = TreeNode(7)
    root.left.right.right = TreeNode(4)

    p = root.left
    q = root.left.right.right

    solution = Solution()
    result = solution.lowestCommonAncestor(root, p, q)

    if result is not None:
        print(
            f"Lowest Common Ancestor of {p.val} and {q.val}: "
            f"{result.val}"
        )


if __name__ == "__main__":
    main()
