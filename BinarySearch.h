#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

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

    // Private member functions for internal use
    TreeNode* insertRecByID(TreeNode* root, const NodeData& data);
    bool searchRecByID(TreeNode* root, int id);
    TreeNode* deleteRecByID(TreeNode* root, int id);
    TreeNode* minValueNode(TreeNode* node);

public:
    BinarySearchTree(); // Constructor
    ~BinarySearchTree(); // Destructor
    void insertByID(const NodeData& data);
    bool searchByID(int id);
    void deleteNodeByID(int id);
};

#endif
