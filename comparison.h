// Tawhid Taher Chowdhury


#ifndef COMPARISON_H
#define COMPARISON_H

#include <string>
#include <iostream>

// Node structure for LinkedList
struct ListNode {
    std::string name;
    std::string DOB;
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
    ListNode* next;
};

// Node structure for Binary Search Tree
struct TreeNode {
    std::string name;
    std::string DOB;
    std::string street;
    std::string city;
    std::string state;
    std::string zip;
    TreeNode* left;
    TreeNode* right;
};

// Function declarations for LinkedList
void insertListNode(ListNode*& head, const std::string& data);
void displayList(ListNode* head);
void deleteList(ListNode*& head);
ListNode* searchList(ListNode* head, const std::string& name);

// Function declarations for Binary Search Tree
void insertTreeNode(TreeNode*& root, const std::string& data);
void displayTreeInOrder(TreeNode* root);
void deleteTree(TreeNode*& root);
TreeNode* searchTree(TreeNode* root, const std::string& name);

#endif // COMPARISON_H
