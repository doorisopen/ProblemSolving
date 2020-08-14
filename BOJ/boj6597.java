import java.util.*;
class Tree {
    class Node {
        char data;
        Node left, right;
        Node(char data) {
            this.data = data;
        }
    }
    Node root;
    static int pIndex = 0;
    public void buildTreeByInPre(char in[], char pre[]) {
        pIndex = 0;
        root = buildTreeByInPre(in, pre, 0, in.length - 1);
    }

    private Node buildTreeByInPre(char[] in, char[] pre, int start, int end) {
        if(start > end) return null;
        Node node = new Node(pre[pIndex++]);
        if(start == end) return node;
        int mid = search(in, start, end, node.data);
        node.left = buildTreeByInPre(in, pre, start, mid-1);
        node.right = buildTreeByInPre(in, pre, mid+1, end);
        return node;
    }
    private int search(char[] in, int start, int end, char data) {
        int i = 0;
        for (i = start; i <= end; i++) {
            if(in[i] == data) return i;
        }
        return i;
    }
    public void printInorder(Node node) {
        if(node == null) return;
        printInorder(node.left);
        printInorder(node.right);
        System.out.print(node.data);
    }
    
}
    public class boj6597 {
    public static void main(String args[]) {  
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()) {
            String str = sc.nextLine();
            String inpre[] = str.split(" ");
            Tree tree = new Tree();
            char pre[] = new char[inpre[0].length()];
            char in[] = new char[inpre[1].length()];
            for (int i = 0; i < inpre[0].length(); i++) {
                pre[i] = inpre[0].charAt(i);
            }
            for (int i = 0; i < inpre[1].length(); i++) {
                in[i] = inpre[1].charAt(i);
            }
            tree.buildTreeByInPre(in, pre);
            tree.printInorder(tree.root);
            System.out.print("\n");
        }
        sc.close();
    }
}