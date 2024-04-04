#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;
int displaymenu(){//menu function to keep main short and efficient
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

int main(){
LinkedList StudentList;

//StudentList.Addperson(2021,"john", "01/01/2002", "Hickory","denton","TX",76201);
int C;
    do{//do while llop to ensure all functions are accesible and menu will pop up until usser exits program.
    C = displaymenu();
    if(C == 1){ 
        string n;
        string dob, a,a2,a3;
        int id, a4;
        cout << "Enter name: ";
        cin >> n;
        //getline(cin,n);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Date of Birth: ";
        cin.ignore();
        getline(cin,dob);
        cout << "Address(Street): ";
        cin >> a;
        cout << "Address(City): ";
        cin >> a2;
        cout << "Address(State): ";
        
        cin>> a3;
        cout << "Address(Zip Code): ";
        
        cin >> a4;
        StudentList.Addperson(id,n,dob,a,a2,a3,a4);}
     else if (C ==2){
        int id; 
        cout << "Enter students ID: ";
        cin >> id;
        StudentList.DeletePerson(id);
        break;
    }
    else if(C == 3){
        int id;
        cout << "Enter students ID: ";
        cin >> id;
        Node* student = StudentList.SearchPerson(id);
        if(student!= nullptr){
            cout << "Student located: "<< student->name<<endl;
        }
        else{
            cout << "Id provided is not found in our Student List"<<endl;
        }
        break;
    }
    else if(C== 4){
        StudentList.DisplayEveryone();
        break;
    }
    else if(C == 5){
        
        string n;
        cout << "Enter student name: ";
        cin >> n;
        Node* student = StudentList.SearchPersonN(n);
        if(student!= nullptr){
            cout << "Student located: "<< "name: "<< student->name<<endl;
            cout << "ID: "<< student->ID << endl; 
            cout << "DOB: "<< student->DOB<<endl;
        }
        else{
            cout << "Name provided is not found in our Student List"<<endl;
        }
        break;
    }
    else if(C == 6){
        int n;
        cout << "Enter ID: ";
        cin >> n;
        StudentList.UpdateInfo(n);
    }

    }while (C != 7);
   //end of program
    return 0;
}

