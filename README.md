#DSA-Final-Project

How to Run

Run this command : make

then run : ./a.out

Portions
Python Faker Library, Linked List, Binary Search Tree, Run Time Analysis, Comparison Analysis

Instructions
INSTRUCTIONS: Final project of my Data Structures and Algorithms class (CSCE 3110).

GUIDELINES: Dear Students,

This explains the basic requirements of the class group project.

We must implement a student management system and store student records in an in-memory data structure.

We must use two different data structures.

Linked List

Binary Search Tree

Requirements:

You must have the following features implemented.

add a student to the existing database.

Delete a student from the database once the student ID is given

search for a student with an ID

Search for a student with a name in case the student ID is not available

update student records when the student ID is given. This feature must allow the user to see the current information and a chance to modify any information except student ID.

Insert 100,000 students into the system. You can use a faker library to generate a list of students.

One possible candidate is https://github.com/cieslarmichal/faker-cxxLinks to an external site.

Use this library to create a list of fake students with the following information

Name: The first name is enough

DOB:

Address: street

Address: city

Address: State

Address: zip

You may use other faker libraries, such as Python libraries, write them to a file, and later read it into a C++ program.

Python Faker: https://faker.readthedocs.io/en/master/

You must provide the answers to the following questions.

What is the run time of each operation (1 to 5 given above)for the Linked List and Binary Search tree?

Make a comparison between Linked List and Binary Search Tree.

Submission guidelines:

Submit your code as a zipped file.

Document your system. Include some screenshots that display the five features that you implemented. Submit this doc file along side of your code file.

Contributions:
Ryan Ghandour Linked List Portion: The linked list class comprised of using a struct to create our Nodes, while using a class to set up our Linked List. Its functionality includes having a default constructor, a add, delete, search, based on both name and ID, display, and finally a update info function. These functions were implemented in the H file and then the functionality is present in the CPP file. The code mainly uses pointers to traverse throughout the singly linked list by using the next pointer which is a member of our struct. This allows us to minimize our runtime and make sure it is as efficient as possible without using an excess amount of four loops or if statements which will increase the runtime of each of the functions leading to a less efficient algorithm. The search function is present for both name and ID as specified in the requirements due to the possibility of an ID not being present for an individual therefore searching by name would be the only other solution. Our delete function uses the ID of the student as one of its parameters thereby allowing us to iterate through and delete the specified person. Our update info function is where we allow the user to alter already present information for any individual in the list and we give them the functionality of choosing whatever personal information they would like to alter or change.
