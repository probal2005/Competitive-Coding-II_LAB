class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class Solution:
    def inorderSuccessor(self, root, p):
        successor = None

        while root is not None:
            if p.val < root.val:
                successor = root
                root = root.left
            else:
                root = root.right

        return successor


def main():
    """
              5
             / \
            3   6
           / \
          2   4
         /
        1
    """

    root = TreeNode(5)

    root.left = TreeNode(3)
    root.right = TreeNode(6)

    root.left.left = TreeNode(2)
    root.left.right = TreeNode(4)

    root.left.left.left = TreeNode(1)

    # Find the inorder successor of node 3.
    p = root.left

    solution = Solution()
    result = solution.inorderSuccessor(root, p)

    if result is not None:
        print(f"Inorder Successor of {p.val}: {result.val}")
    else:
        print(f"Inorder Successor of {p.val}: Does not exist")


if __name__ == "__main__":
    main()
