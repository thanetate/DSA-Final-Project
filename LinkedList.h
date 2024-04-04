
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
using namespace std;

struct Node{
    int ID,a4;
    string name;
    string DOB;
    Node * next;
    string address,a2,a3;

    Node(int id, string n, string dob, string a,string s, string b, int g): name(n), DOB(dob), ID(id), next(nullptr), address(a),a2(s),a3(b),a4(g){}
};

class LinkedList {
    private: 
    Node* Head;

    public:
    LinkedList();
    void Addperson(int id, string name, string dob, string a, string a2, string a3, int a4);
    void DeletePerson(int id);
    void DisplayEveryone();
    Node* SearchPerson(int id);
    Node* SearchPersonN(string n);
    //void reverseList();
    void UpdateInfo(int id);
    ~LinkedList();
};


#endif