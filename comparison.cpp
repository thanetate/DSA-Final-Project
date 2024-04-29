// Tawhid Taher Chowdhury

#include "comparison.h"
#include <sstream>

// Helper function to create a new ListNode
ListNode* createListNode(const std::string& line) {
    std::stringstream ss(line);
    ListNode* newNode = new ListNode();
    std::getline(ss, newNode->name, ',');
    std::getline(ss, newNode->DOB, ',');
    std::getline(ss, newNode->street, ',');
    std::getline(ss, newNode->city, ',');
    std::getline(ss, newNode->state, ',');
    std::getline(ss, newNode->zip);
    newNode->next = nullptr;
    return newNode;
}

// Insert node into LinkedList
void insertListNode(ListNode*& head, const std::string& data) {
    ListNode* newNode = createListNode(data);
    if (!head) {
        head = newNode;
    } else {
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Display LinkedList
void displayList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << "Name: " << current->name << ", City: " << current->city << std::endl;
        current = current->next;
    }
}

// Delete all nodes in LinkedList
void deleteList(ListNode*& head) {
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// Search for a name in LinkedList
ListNode* searchList(ListNode* head, const std::string& name) {
    ListNode* current = head;
    while (current) {
        if (current->name == name) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Helper function to create a new TreeNode
TreeNode* createTreeNode(const std::string& line) {
    std::stringstream ss(line);
    TreeNode* newNode = new TreeNode();
    std::getline(ss, newNode->name, ',');
    std::getline(ss, newNode->DOB, ',');
    std::getline(ss, newNode->street, ',');
    std::getline(ss, newNode->city, ',');
    std::getline(ss, newNode->state, ',');
    std::getline(ss, newNode->zip);
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Insert node into Binary Search Tree
void insertTreeNode(TreeNode*& root, const std::string& data) {
    TreeNode* newNode = createTreeNode(data);
    if (!root) {
        root = newNode;
    } else {
        TreeNode* parent = nullptr, * current = root;
        while (current) {
            parent = current;
            if (newNode->name < current->name) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (newNode->name < parent->name) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
}

// Display BST in order
void displayTreeInOrder(TreeNode* root) {
    if (root) {
        displayTreeInOrder(root->left);
        std::cout << "Name: " << root->name << ", City: " << root->city << std::endl;
        displayTreeInOrder(root->right);
    }
}

// Delete all nodes in Binary Search Tree
void deleteTree(TreeNode*& root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr;
    }
}

// Search for a name in Binary Search Tree
TreeNode* searchTree(TreeNode* root, const std::string& name) {
    while (root) {
        if (name < root->name) {
            root = root->left;
        } else if (name > root->name) {
            root = root->right;
        } else {
            return root; // Name matches
        }
    }
    return nullptr; // Not found
}

// Main function
int main() {
    // Testing Data
    std::string data1 = "John Doe,1990-01-01,123 Main St,Anytown,Anystate,12345";
    std::string data2 = "Jane Smith,1992-02-01,456 Elm St,Anothertown,Anystate,23456";
    std::string data3 = "Alice Johnson,1993-03-01,789 Oak St,Yetanothertown,Anystate,34567";

    // Linked List
    ListNode* listHead = nullptr;
    insertListNode(listHead, data1);
    insertListNode(listHead, data2);
    insertListNode(listHead, data3);
    std::cout << "Linked List:" << std::endl;
    displayList(listHead);
    ListNode* foundList = searchList(listHead, "Jane Smith");
    if (foundList) {
        std::cout << "Found in list: " << foundList->name << std::endl;
    }
    deleteList(listHead);

    // Binary Search Tree
    TreeNode* treeRoot = nullptr;
    insertTreeNode(treeRoot, data1);
    insertTreeNode(treeRoot, data2);
    insertTreeNode(treeRoot, data3);
    std::cout << "Binary Search Tree:" << std::endl;
    displayTreeInOrder(treeRoot);
    TreeNode* foundTree = searchTree(treeRoot, "Jane Smith");
    if (foundTree) {
        std::cout << "Found in tree: " << foundTree->name << std::endl;
    }
    deleteTree(treeRoot);

    return 0;
}
