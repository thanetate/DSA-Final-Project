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
    TreeNode* insertRec(TreeNode* root, const NodeData& data);
    bool searchRecInt(TreeNode* root, int id);
    bool searchRecString(TreeNode* root, const string& name);
    TreeNode* deleteRecByName(TreeNode* root, const string& name);
    TreeNode* minValueNode(TreeNode* node);

public:
    BinarySearchTree(); // Constructor
    ~BinarySearchTree(); // Destructor
    void insert(const NodeData& data);
    bool searchId(int id);
    bool searchName(string name);
    bool searchDOB(string dob);
    bool searchStreet(string street);
    bool searchCity(string city);
    bool searchState(string state);
    bool search(int zip);
    void deleteNodeByName(const string& name);
};

#endif