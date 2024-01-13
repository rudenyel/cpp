#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;
    Node(T data) : data(data), left(nullptr), right(nullptr) {}
    ~Node() {}
    T getData() { return data; }
};

template <typename T>
struct BSTree {
    Node<T>* root;
    BSTree() : root(nullptr) {}
    ~BSTree() { destroy(root); }

    BSTree& push(T data) { 
        if (root == nullptr) { root = add(root, data); }
        else { add(root, data); }
        return *this;
    }
    
    BSTree& pop(T data) { remove(root, data); return *this; }

private:
    static void destroy(Node<T>* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
};

template <typename T>
Node<T>* add(Node<T>* node, T data) {
    if (node == nullptr) { return new Node<T>(data); }
    else if (data < node->data) { node->left = add(node->left, data); }
    else if (data > node->data) { node->right = add(node->right, data); }
    return node;
}

template <typename T>
Node<T>* remove(Node<T>* node, T data) {
    if (node == nullptr) { return nullptr; }
    if (data < node->data) { node->left = remove(node->left, data); }
    else if (data > node->data) { node->right = remove(node->right, data); }
    else if (node->left != nullptr and node->right != nullptr) { 
        node->data = minimum(node->right)->data;
        node->right = remove(node->right, node->data);
    }
    else
        if (node->left != nullptr) { node = node->left; }
        else if (node->right != nullptr) { node = node->right; }
        else { node = nullptr; }
    return node;
}

template <typename T>
Node<T>* search(Node<T>* node, T data) {
    if (node == nullptr || node->data == data) { return node; }
    else if (data < node->data) { return search(node->left, data); }
    else { return search(node->right, data); }
}

template <typename T>
Node<T>* minimum(Node<T>* node) {
    if (node->left == nullptr) { return node; }
    return minimum(node->left);
}

template <typename T>
Node<T>* maximum(Node<T>* node) {
    if (node->right == nullptr) { return node; }
    return maximum(node->right);
}

template <typename T>
void inorderTraversal(Node<T>* node) {
    if (node) {
        inorderTraversal(node->left);
        cout << node->getData() << " ";
        inorderTraversal(node->right);
    }
}

template <typename T>
void preorderTraversal(Node<T>* node) {
    if (node) {
        cout << node->getData() << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);

    }
}

template <typename T>
void postorderTraversal(Node<T>* node) {
    if (node) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->getData() << " ";

    }
}

int main()
{
    BSTree<int> tree;

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

    cout << "inorder traversal:" << std::endl;
    inorderTraversal(tree.root);
    cout << std::endl;
    cout << "preorder traversal:" << std::endl;
    preorderTraversal(tree.root);
    cout << std::endl;
    cout << "postorder traversal:" << std::endl;
    postorderTraversal(tree.root);
    cout << std::endl;
    cout << "search node 6 and inorder traversal subtree:" << std::endl;
    Node<int>* node = search(tree.root, 6);
    inorderTraversal(node);
    cout << std::endl;
    node = minimum(tree.root);
    cout << "minimum: " << node->getData() << std::endl;
    node = maximum(tree.root);
    cout << "maximum: " << node->getData() << std::endl;
    cout << "delete root node 8 and inorder traversal:" << std::endl;
    tree.pop(8);
    inorderTraversal(tree.root);
}
