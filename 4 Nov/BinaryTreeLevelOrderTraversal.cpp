#include <iostream>
#include <queue>
using namespace std;

// Define the Node class for the binary tree
class TreeNode {
public:
    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;

    TreeNode(int data) {
        this->value = data;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
};

// Function to build the binary tree
TreeNode* createTree(TreeNode* root) {
    int value;
    cout << "Enter the value for the node (-1 for NULL): ";
    cin >> value;

    if (value == -1) {
        return nullptr;
    }

    root = new TreeNode(value);
    cout << "Enter the value for the left child of " << value << ": ";
    root->leftChild = createTree(root->leftChild);

    cout << "Enter the value for the right child of " << value << ": ";
    root->rightChild = createTree(root->rightChild);

    return root;
}

// Function for level-order traversal of the binary tree
void levelOrder(TreeNode* root) {
    if (root == nullptr) {
        cout << "The tree is empty.\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    cout << "Level Order Traversal: ";
    while (!q.empty()) {
        TreeNode* currentNode = q.front();
        q.pop();

        cout << currentNode->value << " ";

        if (currentNode->leftChild) {
            q.push(currentNode->leftChild);
        }
        if (currentNode->rightChild) {
            q.push(currentNode->rightChild);
        }
    }
    cout << endl;
}

int main() {
    TreeNode* root = nullptr;

    // Build the tree
    cout << "Creating the binary tree...\n";
    root = createTree(root);

    // Perform level-order traversal
    cout << "\nPerforming level-order traversal of the binary tree:\n";
    levelOrder(root);

    return 0;
}
