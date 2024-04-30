#include "BinarySearch.h"

// insert function
TreeNode* BinarySearchTree::insertRecByID(TreeNode* root, const NodeData& data) {
    if (root == nullptr) {
        return new TreeNode(data);
    }

    if (data.id < root->data.id) {
        root->left = insertRec(root->left, data);
    } else if (data.id > root->data.id) {
        root->right = insertRec(root->right, data);
    }

    return root;
}

// search funtion for nodes ID
bool BinarySearchTree::searchRecByID(TreeNode* root, int id) {
    if (root == nullptr) {
        return false;
    }

    if (root->data.id == id) {
        return true;
    } else if (id < root->data.id) {
        return searchRecInt(root->left, id);
    } else {
        return searchRecInt(root->right, id);
    }
}

// Helper function to find minimum value node in a subtree
TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;

    // Find the leftmost leaf node
    while (current && current->left != nullptr) {
        current = current->left;
    }

    return current;
}


// function for deletion for ID
TreeNode* deleteRecByID(TreeNode* root, int id) {
    if (root == nullptr) {
        return root;
    }

    // Recur down the tree
    if (id < root->data.id) {
        root->left = deleteRecByID(root->left, id);
    } else if (id > root->data.id) {
        root->right = deleteRecByID(root->right, id);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteRecByID(root->right, temp->data.id);
    }
    return root;
}

public:
// Function to insert a node into the tree by ID
void insertByID(const NodeData& data) {
    root = insertRecByID(root, data);
}

// Function to delete a node from the tree by ID
void deleteNodeByID(int id) {
    root = deleteRecByID(root, id);
}

// Function to search for a node in the tree by ID
bool searchByID(int id) {
     return searchRecByID(root, id);
}
