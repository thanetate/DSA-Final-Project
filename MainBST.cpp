//Ryan Brown

#include <iostream>
#include <string>

using namespace std;

// struct for all the data for the proj
struct NodeData {
    int id;
    string name;
    string dob;
    string street;
    string city;
    string state;
    int zip;
};

// struct for the tree
struct TreeNode {
    NodeData data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const NodeData& d) : data(d), left(nullptr), right(nullptr) {}
};

// bst class
class BinarySearchTree {
private:
    TreeNode* root;

    // insert function
    TreeNode* insertRec(TreeNode* root, const NodeData& data) {
        if (root == nullptr) {
            return new TreeNode(data);
        }

        if (data.id < root->data.id) {
            root->left = insertRec(root->left, data);
        }
        else if (data.id > root->data.id) {
            root->right = insertRec(root->right, data);
        }

        return root;
    }

    // search funtion for integers
    bool searchRecInt(TreeNode* root, int id) {
        if (root == nullptr) {
            return false;
        }

        if (root->data.id == id) {
            return true;
        }
        else if (id < root->data.id) {
            return searchRecInt(root->left, id);
        }
        else {
            return searchRecInt(root->right, id);
        }
    }

    // search function for strings
    bool searchRecString(TreeNode* root, const string& name) {
        if (root == nullptr) {
            return false;
        }

        if (root->data.name == name) {
            return true;
        }
        else if (name < root->data.name) {
            return searchRecString(root->left, name);
        }
        else {
            return searchRecString(root->right, name);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Function to insert a node into the tree
    void insert(const NodeData& data) {
        root = insertRec(root, data);
    }

    // search by ID
    bool searchId(int id) {
        return searchRecInt(root, id);
    }

    // search by name
    bool searchName(string name) {
        return searchRecString(root, name);
    }
    // search by dob
    bool searchDOB(string dob) {
        return searchRecString(root, dob);
    }
    // search by street
    bool searchStreet(string street) {
        return searchRecString(root, street);
    }
    // search by city
    bool searchCity(string city) {
        return searchRecString(root, city);
    }
    // search by state
    bool searchState(string state) {
        return searchRecString(root, state);
    }
    // search by zip
    bool search(int zip) {
        return searchRecInt(root, zip);
    }
};


