#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Node structure for Linked List
struct Node {
    int ID;
    string name;
    string DOB;
    string street;
    string city;
    string state;
    int zip;
    Node* next;

    Node(int id, const string& n, const string& dob, const string& a, const string& a2, const string& a3, int a4)
        : ID(id), name(n), DOB(dob), street(a), city(a2), state(a3), zip(a4), next(nullptr) {}
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to add a person to the linked list
    void AddPerson(int id, const string& n, const string& dob, const string& a, const string& a2, const string& a3, int a4) {
        Node* newNode = new Node(id, n, dob, a, a2, a3, a4);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to display everyone in the linked list
    void DisplayEveryone() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->ID << ", Name: " << temp->name << ", DOB: " << temp->DOB << ", Address: " << temp->street << ", " << temp->city << ", " << temp->state << ", " << temp->zip << endl;
            temp = temp->next;
        }
    }

    // Function to search for a person by ID
    Node* SearchPerson(int id) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->ID == id) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Function to search for a person by name
    Node* SearchPersonN(const string& n) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->name == n) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Function to update information of a person by ID
    void UpdateInfo(int id) {
        Node* temp = SearchPerson(id);
        if (temp != nullptr) {
            // Add your update logic here
            cout << "Information updated for ID: " << id << endl;
        } else {
            cout << "ID not found." << endl;
        }
    }

    // Function to delete a person by ID
    void DeletePerson(int id) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->ID == id) {
                if (previous != nullptr) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                cout << "Person with ID " << id << " has been deleted." << endl;
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Person with ID " << id << " not found." << endl;
    }
};

// struct for all the data for the project
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

// BST class
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
        } else if (data.id > root->data.id) {
            root->right = insertRec(root->right, data);
        }

        return root;
    }

    // search function for integers
    bool searchRecInt(TreeNode* root, int id) {
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
    bool searchRecString(TreeNode* root, const string& name) {
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
    TreeNode* deleteRecByName(TreeNode* root, const string& name) {
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

            // two children node
            TreeNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteRecByName(root->right, temp->data.name);
        }
        return root;
    }

    // helper function to find the node with minimum value
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;

        // loop down to find the leftmost leaf
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
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

    // Function to delete a node from the tree by name of ints or strings
    void deleteNodeByName(const string& name) {
        root = deleteRecByName(root, name);
    }
};

// struct for fake data
struct FakeData {
    string name;
    string DOB;
    string street;
    string city;
    string state;
    string zip;
    FakeData* next;
};

// Function to read fake data from CSV
FakeData* read_fake_data(const string& file_path) {
    ifstream file(file_path);

    if (!file.is_open()) {
        cout << "Error, could not open file path: " << file_path << endl;
        exit(-1);
    }

    string line;
    getline(file, line);

    FakeData* head = nullptr;
    FakeData* current = nullptr;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        FakeData* newNode = new FakeData();

        getline(ss, token, ','); //Read name
        newNode->name = token;

        getline(ss, token, ','); //Read DOB
        newNode->DOB = token;

        getline(ss, token, ','); //Read street
        newNode->street = token;

        getline(ss, token, ','); //Read city
        newNode->city = token;

        getline(ss, token, ','); //Read state
        newNode->state = token;

        getline(ss, token);      //Read zip
        newNode->zip = token;

        newNode->next = nullptr;

        //insert into linked list
        if (!head) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }

    file.close();
    return head;
}

int main() {
    LinkedList StudentList;
    BinarySearchTree bst;

    // Read fake data from CSV
    FakeData* fakeDataHead = read_fake_data("fake_data.csv");
    FakeData* current = fakeDataHead;

    // Add fake data to both linked list and binary search tree
    while (current != nullptr) {
    NodeData newData = {stoi(current->zip), current->name, current->DOB, current->street, current->city, current->state, stoi(current->zip)};
    StudentList.AddPerson(newData.id, newData.name, newData.dob, newData.street, newData.city, newData.state, newData.zip);
    bst.insert(newData);
    current = current->next;
}


    // Display menu and interact with the user
    int choice;
    do {
        cout << "Menu: " << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Search for Student by ID" << endl;
        cout << "4. Search for Student by Name" << endl;
        cout << "5. Display all Students" << endl;
        cout << "6. Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string name, dob, street, city, state;
                int zip;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Date of Birth: ";
                cin >> dob;
                cout << "Enter Street: ";
                cin >> street;
                cout << "Enter City: ";
                cin >> city;
                cout << "Enter State: ";
                cin >> state;
                cout << "Enter Zip Code: ";
                cin >> zip;

                NodeData newData;
                newData.id = id;
                newData.name = name;
                newData.dob = dob;
                newData.street = street;
                newData.city = city;
                newData.state = state;
                newData.zip = zip;

                StudentList.AddPerson(id, name, dob, street, city, state, zip);
                bst.insert(newData);
                break;
            }
            case 2: {
                int id;
                cout << "Enter Student ID to delete: ";
                cin >> id;
                StudentList.DeletePerson(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter Student ID to search: ";
                cin >> id;
                if (bst.searchId(id)) {
                    cout << "Student with ID " << id << " found." << endl;
                } else {
                    cout << "Student with ID " << id << " not found." << endl;
                }
                break;
            }
            case 4: {
                string name;
                cout << "Enter Student Name to search: ";
                cin >> name;
                if (bst.searchName(name)) {
                    cout << "Student with Name " << name << " found." << endl;
                } else {
                    cout << "Student with Name " << name << " not found." << endl;
                }
                break;
            }
            case 5: {
                cout << "Displaying all students:" << endl;
                StudentList.DisplayEveryone();
                break;
            }
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    // Free memory allocated for fake data linked list
    FakeData* temp = fakeDataHead;
    while (fakeDataHead != nullptr) {
        temp = fakeDataHead;
        fakeDataHead = fakeDataHead->next;
        delete temp;
    }

    return 0;
}
