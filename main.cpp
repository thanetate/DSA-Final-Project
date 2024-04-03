/* TEST */
//g++ -o fake_data main.cpp -ljsoncpp

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct FakeData {
    string name;
    string DOB;
    string street;
    string city;
    string state;
    string zip;
    FakeData* next;
};

//Thane Tate
FakeData* read_fake_data(const string& file_path) {
    //ifstream
    ifstream file(file_path);

    //check
    if(!file.is_open()){
        cout<<"Error, could not open file path: "<<file_path<<endl;
        exit(-1);
    }

    string line;
    getline(file, line);

    FakeData* head = nullptr;
    FakeData* current = nullptr;

    while(getline(file, line)){
        stringstream ss(line);
        string token;

        //new node 
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


int main()
{
    FakeData* head = read_fake_data("fake_data.csv");
    
   
    return 0;
}
