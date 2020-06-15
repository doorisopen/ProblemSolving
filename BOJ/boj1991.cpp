#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    //생성자
    Node(char data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

typedef struct Tree {
    Node* root;
    //생성자
    Tree() {
        root = NULL;
    }
    //노드 생성
    void nodeInsert(char data, char left, char right) {
        if(root == NULL) {
            if(data != '.') root = new Node(data);
            if(left != '.') root->left = new Node(left);
            if(right != '.') root->right = new Node(right);
        } else {
            nodeSearch(root, data, left, right);
        }
    }
    //노드 찾기
    void nodeSearch(Node* root, char data, char left, char right) {
        if(root == NULL) return;
        else if(root->data == data) {
            if(left != '.') root->left = new Node(left);
            if(right != '.') root->right = new Node(right);
        } else {
            nodeSearch(root->left, data, left, right);
            nodeSearch(root->right, data, left, right);
        }
    }
} Tree;

void pre(Node* root) {
    cout << root->data;
    if(root->left != NULL) pre(root->left);
    if(root->right != NULL) pre(root->right);
}
void in(Node* root) {
    if(root->left != NULL) in(root->left);
    cout << root->data;
    if(root->right != NULL) in(root->right);
}
void post(Node* root) {
    if(root->left != NULL) post(root->left);
    if(root->right != NULL) post(root->right);
    cout << root->data;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    Tree tree;
    for (int i = 0; i < n; i++) {
        char data, left, right;
        cin >> data >> left >> right;
        tree.nodeInsert(data, left, right);
    }
    
    pre(tree.root);cout<<"\n";
    in(tree.root);cout<<"\n";
    post(tree.root);
    
    return 0;
}