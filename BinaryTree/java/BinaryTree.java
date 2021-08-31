import java.util.LinkedList;
import java.util.Queue;

/**
 * BinaryTree
 */
public class BinaryTree {

    /**
     * InnerBinaryTree
     */
    public class BinaryTreeNode {

        protected int data;
        protected BinaryTreeNode left;
        protected BinaryTreeNode right;

        public BinaryTreeNode(int data) {
            this.data = data;
        }
    }

    private BinaryTreeNode root;

    public BinaryTree() {

    }

    public void insert(int data) {
        this.root = insert(this.root, data);
    }

    private BinaryTreeNode insert(BinaryTreeNode node, int data) {
        if (node == null) {
            node = new BinaryTreeNode(data);
        } else if (node.data > data) {
            node.left = insert(node.left, data);
        } else if (node.data < data) {
            node.right = insert(node.right, data);

        }
        return node;

    }

    // 层序遍历
    public void levelOrder() {
        levelOrder(root);

    }

    private void levelOrder(BinaryTreeNode root) {
        Queue<BinaryTreeNode> dQueue = new LinkedList<>();
        dQueue.add(root);
        while (!dQueue.isEmpty()) {
            BinaryTreeNode node = dQueue.poll();
            System.out.println("data  = " + node.data);
            if (node.left != null) {
                dQueue.add(node.left);
            }
            if (node.right != null) {
                dQueue.add(node.right);
            }
        }
    }
}