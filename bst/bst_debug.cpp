#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
    Node(T data) : data(data), left(nullptr), right(nullptr) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        cout << "constructor: add new node " << this->data << std::endl;
    }
    ~Node() {}
    T getData() { return data; }
};

template <typename T>
struct BSTree {
    Node<T>* root;
    BSTree() {
        this->root = nullptr;
        cout << "new binary search tree, root = nullptr" << std::endl;
    }
    ~BSTree() {
        cout << "begin recursive destroy from root" << std::endl;
        destroy(root);
        cout << "destroy root node, end destroy" << std::endl;
    }

    BSTree& push(T data) {
        cout << "adding data " << data << " to the tree" << std::endl;
        if (root == nullptr) { root = add(root, data); }
        else { add(root, data); }
        return *this;
    }

private:
    static void destroy(Node<T>* node) {
        if (node) {
            cout << "current node " << node->getData();
            if (node->left == nullptr) cout << ", left is nullptr" << std::endl;
            else cout << ", move to left" << std::endl;
            destroy(node->left);
            cout << "current node " << node->getData();
            if (node->right == nullptr) cout << ", right is nullptr" << std::endl;
            else cout << ", move to right" << std::endl;
            destroy(node->right);
            cout << "destroy data " << node->getData() << std::endl;
            delete node;
        }
    }
};


template <typename T>
Node<T>* add(Node<T>* node, T data) {
    if (node == nullptr) { 
        return new Node<T>(data); 
    }
    else if (data < node->data) { 
        cout << "current node " << node->getData() << ", move to left" << std::endl;
        node->left = add(node->left, data); 
    }
    else if (data > node->data) { 
        cout << "current node " << node->getData() << ", move to right" << std::endl;
        node->right = add(node->right, data); 
    }
    else {
        cout << "data " << node->getData() << " is in the set, do nothing" << std::endl;
    }
    return node;
}

template <typename T>
void inorderTraversal(Node<T>* node) {
    if (node) {
        cout << "current node " << node->getData() << ", move to left" << std::endl;
        inorderTraversal(node->left);
        cout << "data " << node->getData() << std::endl;
        cout << "current node " << node->getData() << ", move to right" << std::endl;
        inorderTraversal(node->right);
    }
    else {
        cout << "next node is null" << std::endl;
    }
}

template <typename T>
void preorderTraversal(Node<T>* node) {
    if (node) {
        cout << "data " << node->getData() << std::endl;
        cout << "current node " << node->getData() << ", move to left" << std::endl;
        preorderTraversal(node->left);
        cout << "current node " << node->getData() << ", move to right" << std::endl;
        preorderTraversal(node->right);

    }
    else {
        cout << "next node is null" << std::endl;
    }
}

template <typename T>
void postorderTraversal(Node<T>* node) {
    if (node) {

        cout << "current node " << node->getData() << ", move to left" << std::endl;
        postorderTraversal(node->left);
        cout << "current node " << node->getData() << ", move to right" << std::endl;
        postorderTraversal(node->right);
        cout << "data " << node->getData() << std::endl;

    }
    else {
        cout << "next node is null" << std::endl;
    }
}

int main()
{
    BSTree<int> tree;

    cout << std::endl;
    tree.push(8);
    tree.push(3);
    tree.push(10);
    tree.push(10);
    tree.push(1);
    tree.push(6);
    tree.push(14);
    tree.push(4);
    tree.push(7);
    tree.push(13);

    cout << std::endl;
    cout << "begin recursive inorder traversal" << std::endl;
    inorderTraversal(tree.root);

    cout << std::endl;
    cout << "begin recursive preorder traversal" << std::endl;
    preorderTraversal(tree.root);

    cout << std::endl;
    cout << "begin recursive postorder traversal" << std::endl;
    postorderTraversal(tree.root);

    cout << std::endl;
}