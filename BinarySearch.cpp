#include "BinarySearch.h"

// insert function
TreeNode* BinarySearchTree::insertRec(TreeNode* root, const NodeData& data) {
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

// search funtion for integers
bool BinarySearchTree::searchRecInt(TreeNode* root, int id) {
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

// search function for strings
bool BinarySearchTree::searchRecString(TreeNode* root, const string& name) {
    if (root == nullptr) {
        return false;
    }

    if (root->data.name == name) {
        return true;
    } else if (name < root->data.name) {
        return searchRecString(root->left, name);
    } else {
        return searchRecString(root->right, name);
    }
}

// function for deletion for ints and strings
TreeNode* BinarySearchTree::deleteRecByName(TreeNode* root, const string& name) {
    if (root == nullptr) {
        return root;
    }

    // Recur down the tree
    if (name < root->data.name) {
        root->left = deleteRecByName(root->left, name);
    } else if (name > root->data.name) {
        root->right = deleteRecByName(root->right, name);
    } else {
        // Node with only one child/no child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        //two children node
        TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteRecByName(root->right, temp->data.name);
    }
    return root;
}

TreeNode* BinarySearchTree::minValueNode(TreeNode* node) {
    TreeNode* current = node;

    // Find the leftmost leaf node
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Public member functions

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    // Implement tree deletion here if needed
}
// Function to insert a node into the tree
void BinarySearchTree::insert(const NodeData& data) {
    root = insertRec(root, data);
}
// search by ID
bool BinarySearchTree::searchId(int id) {
    return searchRecInt(root, id);
}
// search by name
bool BinarySearchTree::searchName(string name) {
    return searchRecString(root, name);
}
// search by dob
bool BinarySearchTree::searchDOB(string dob) {
    return searchRecString(root, dob);
}
// search by street
bool BinarySearchTree::searchStreet(string street) {
    return searchRecString(root, street);
}
// search by city
bool BinarySearchTree::searchCity(string city) {
    return searchRecString(root, city);
}
// search by state
bool BinarySearchTree::searchState(string state) {
    return searchRecString(root, state);
}
// search by zip
bool BinarySearchTree::search(int zip) {
    return searchRecInt(root, zip);
}
// Function to delete a node from the tree by name of ints or strings
void BinarySearchTree::deleteNodeByName(const string& name) {
    root = deleteRecByName(root, name);
}
