#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
struct Node {
    T data;
    int count;
    Node* left;
    Node* right;
    Node(T data) : data(data), count(0), left(nullptr), right(nullptr) {}
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
    if (node == nullptr) { 
        Node<T>* new_node = new Node<T>(data);
        new_node->count++;
        return new_node;
    }
    else if (data < node->data) { node->left = add(node->left, data); }
    else if (data > node->data) { node->right = add(node->right, data); }
    else { node->count++; }
    return node;
}


template <typename T>
void inorderTraversal(Node<T>* node) {
    if (node) {
        inorderTraversal(node->left);
        cout << node->data << " (" << node->count << ") ";
        inorderTraversal(node->right);
    }
}


int main()
{
    BSTree<string> tree;

    ifstream file;
    file.open("input.txt");
  
    string word;
    while (file >> word)
    {
        tree.push(word);
    }

    inorderTraversal(tree.root);
}