#include <iostream>
#include <string>
#include "LinkedList.h"
#include "BinarySearch.h"
//fake data needs
#include <fstream>
#include <sstream>

using namespace std;

//read fake data from CSV
void ReadandPopulateLinkedList(BinarySearchTree& StudentBST, LinkedList& StudentList, const string& file_path)
{
    ifstream file(file_path);

    if (!file.is_open()) {
        cout << "Error, could not open file path: " << file_path << endl;
        exit(-1);
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        int id;
        string name, dob, street, city, state;
        int zip;

        getline(ss, token, ','); // Read name
        name = token;

        getline(ss, token, ','); // Read DOB
        dob = token;

        getline(ss, token, ','); // Read street
        street = token;

        getline(ss, token, ','); // Read city
        city = token;

        getline(ss, token, ','); // Read state
        state = token;

        getline(ss, token);      // Read zip
        zip = stoi(token);

        //for BST
        NodeData data;
        data.id = id;
        data.name = name;
        data.dob = dob;
        data.street = street;
        data.city = city;
        data.state = state;
        data.zip = zip;

        // Add person to LinkedList
        StudentList.Addperson(id, name, dob, street, city, state, zip);
        // Add person to BST
        //StudentBST.insert(data);
    }

    file.close();

}

//menu function to keep main short and efficient
int displaymenu()
{
    int choice;
    cout << "Menu: "<<endl;
    cout << "1. Add Student"<<endl;
    cout << "2. Delete Student"<<endl;
    cout << "3. Search for Student"<<endl;
    cout << "4. Display all Students"<<endl;
    cout << "5. Search for Student based on Name"<<endl;
    cout << "6. Update Information"<<endl;
    cout << "7. Exit"<< endl;
    cout << " Please type your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    // Linked List
    LinkedList StudentList;
    // BST
    BinarySearchTree StudentBST;

    // read and populate linked list with fake data
    ReadandPopulateLinkedList(StudentBST, StudentList, "fake_data.csv");

    int C;
    do {
        // do while loop to ensure all functions are accessible and menu will pop up until user exits program.
        C = displaymenu();
        switch (C) {
            case 1: {
                string n, dob, a, a2, a3;
                int id, a4;
                cout << "Enter name: ";
                cin >> n;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Date of Birth: ";
                cin.ignore();
                getline(cin, dob);
                cout << "Address (Street): ";
                cin >> a;
                cout << "Address (City): ";
                cin >> a2;
                cout << "Address (State): ";
                cin >> a3;
                cout << "Address (Zip Code): ";
                cin >> a4;
                StudentList.Addperson(id, n, dob, a, a2, a3, a4);
                // BST insertion could be uncommented if implemented
                // StudentBST.insert(newStudent);
                break;
            }
            case 2: {
                int id;
                cout << "Enter student's ID: ";
                cin >> id;
                StudentList.DeletePerson(id);
                // BST deletion could be uncommented if implemented
                // StudentBST.deleteNodebyId(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter student's ID: ";
                cin >> id;
                Node* student = StudentList.SearchPerson(id);
                if (student != nullptr) {
                    cout << "Student located: " << student->name << endl;
                } else {
                    cout << "ID provided is not found in our Student List" << endl;
                }
                // BST search could be included if implemented
                // bool found = StudentBST.searchId(id);
                break;
            }
            case 4:
                StudentList.DisplayEveryone();
                break;
            case 5: {
                string n;
                cout << "Enter student name: ";
                cin >> n;
                Node* student = StudentList.SearchPersonN(n);
                if (student != nullptr) {
                    cout << "Student located: name: " << student->name << endl;
                    cout << "ID: " << student->ID << endl;
                    cout << "DOB: " << student->DOB << endl;
                } else {
                    cout << "Name provided is not found in our Student List" << endl;
                }
                break;
            }
            case 6: {
                int n;
                cout << "Enter ID: ";
                cin >> n;
                StudentList.UpdateInfo(n);
                break;
            }
            case 7:
                cout << "Exiting the program." << endl;
                break; // This break exits the loop
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (C != 7);

    return 0;
}
