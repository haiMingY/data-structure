
/**
 * Main
 */
public class Main {

    public static void main(String[] args) {
        System.out.println("------------");
       BinaryTree tree =new BinaryTree();
       tree.insert(60);
       tree.insert(45);
       tree.insert(20);
       tree.insert(80);
       tree.insert(662);
       tree.insert(10);
       tree.insert(67);
       tree.insert(24);
       tree.levelOrder();
    }
}