import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Node {
    char data;
    Node left, right;
    public Node(char data) {
        this.data = data;
    }
}
class Tree {
    Node root;
    public void nodeInsert(char data, char left, char right) {
        if(root == null) {
            if(data != '.') root = new Node(data);
            if(left != '.') root.left = new Node(left);
            if(right != '.') root.right = new Node(right);
        } else {
            nodeSearch(root, data, left, right);
        }
    }
    public void nodeSearch(Node root, char data, char left, char right) {
        if(root == null) return;
        else if(root.data == data) {
            if(left != '.') root.left = new Node(left);
            if(right != '.') root.right = new Node(right);
        } else {
            nodeSearch(root.left, data, left, right);
            nodeSearch(root.right, data, left, right);
        }
    }
    public void pre(Node root) {
        System.out.print(root.data);
        if(root.left != null) pre(root.left);
        if(root.right != null) pre(root.right);
    }
    public void in(Node root) {
        if(root.left != null) in(root.left);
        System.out.print(root.data);
        if(root.right != null) in(root.right);
    }
    public void post(Node root) {
        if(root.left != null) post(root.left);
        if(root.right != null) post(root.right);
        System.out.print(root.data);

    }
}
public class boj1991 {
    public static void main(String args[]) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(bf.readLine());
        Tree tree = new Tree();
        for (int i = 0; i < n; i++) {
            char str[] = bf.readLine().replace(" ", "").toCharArray();
            tree.nodeInsert(str[0], str[1], str[2]);
        }

        tree.pre(tree.root);
        System.out.println();
        tree.in(tree.root);
        System.out.println();
        tree.post(tree.root);
        System.out.println();
        bf.close();
    }
}