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
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        TreeNode successor = null;

        while (root != null) {
            if (p.val < root.val) {
                successor = root;
                root = root.left;
            } else {
                root = root.right;
            }
        }

        return successor;
    }
}

class Main {
    public static void main(String[] args) {
        /*
                  5
                 / \
                3   6
               / \
              2   4
             /
            1
        */

        TreeNode root = new TreeNode(5);

        root.left = new TreeNode(3);
        root.right = new TreeNode(6);

        root.left.left = new TreeNode(2);
        root.left.right = new TreeNode(4);

        root.left.left.left = new TreeNode(1);

        // Find the inorder successor of node 3.
        TreeNode p = root.left;

        Solution solution = new Solution();
        TreeNode result = solution.inorderSuccessor(root, p);

        if (result != null) {
            System.out.println(
                "Inorder Successor of " + p.val + ": " + result.val
            );
        } else {
            System.out.println(
                "Inorder Successor of " + p.val + ": Does not exist"
            );
        }
    }
}
