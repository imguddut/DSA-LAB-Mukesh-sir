#include <iostream>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// In-order Depth-First Traversal (Left, Root, Right)
void inOrderTraversal(TreeNode *root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    cout << root->value << " ";
    inOrderTraversal(root->right);
}

// Pre-order Depth-First Traversal (Root, Left, Right)
void preOrderTraversal(TreeNode *root) {
    if (root == nullptr) return;
    cout << root->value << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Post-order Depth-First Traversal (Left, Right, Root)
void postOrderTraversal(TreeNode *root) {
    if (root == nullptr) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->value << " ";
}

int main() {
    // Creating a binary tree
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);

    // Traversals
    cout << "In-order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}