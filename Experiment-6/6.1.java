class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

class Solution {
    public TreeNode lowestCommonAncestor(
        TreeNode root,
        TreeNode p,
        TreeNode q
    ) {
        if (root == null || root == p || root == q) {
            return root;
        }

        TreeNode left =
            lowestCommonAncestor(root.left, p, q);

        TreeNode right =
            lowestCommonAncestor(root.right, p, q);

        if (left != null && right != null) {
            return root;
        }

        return (left != null) ? left : right;
    }
}

class Main {
    public static void main(String[] args) {
        /*
                  3
                 / \
                5   1
               / \ / \
              6  2 0  8
                / \
               7   4
        */

        TreeNode root = new TreeNode(3);

        root.left = new TreeNode(5);
        root.right = new TreeNode(1);

        root.left.left = new TreeNode(6);
        root.left.right = new TreeNode(2);

        root.right.left = new TreeNode(0);
        root.right.right = new TreeNode(8);

        root.left.right.left = new TreeNode(7);
        root.left.right.right = new TreeNode(4);

        TreeNode p = root.left;
        TreeNode q = root.left.right.right;

        Solution solution = new Solution();

        TreeNode result =
            solution.lowestCommonAncestor(root, p, q);

        if (result != null) {
            System.out.println(
                "Lowest Common Ancestor of " +
                p.val + " and " + q.val + ": " + result.val
            );
        }
    }
}
