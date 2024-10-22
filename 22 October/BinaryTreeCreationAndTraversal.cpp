#include <iostream>
using namespace std;

// Define the Node structure
struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to print the tree in Pre-order traversal
void printPreorder(TreeNode *root) {
    if (root == nullptr)
        return;
    cout << root->value << " -> ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Function to create a binary tree
void createTree(TreeNode *&root) {
    if (root == nullptr) {
        int value;
        cout << "Enter the value for the node: ";
        cin >> value;
        root = new TreeNode(value);
    }

    // Creating the left child
    string choice;
    cout << "Do you want to create a left child for node " << root->value << "? (y/n): ";
    cin >> choice;
    if (choice == "y" || choice == "Y") {
        createTree(root->left);
    }

    // Creating the right child
    cout << "Do you want to create a right child for node " << root->value << "? (y/n): ";
    cin >> choice;
    if (choice == "y" || choice == "Y") {
        createTree(root->right);
    }
}

// Main function
int main() {
    TreeNode *root = nullptr;

    cout << "Binary Tree Creation\n";
    createTree(root);

    cout << "\nPre-order Traversal of the Tree:\n";
    printPreorder(root);
    cout << "NULL\n";

    return 0;
}
