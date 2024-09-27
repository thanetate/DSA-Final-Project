# Linked List and Binary Tree Project

For our final project in Data Structures and Algorithms, we employed the Python Faker library to generate a substantial dataset of 100,000 fake student records. By utilizing this library, we created diverse and realistic data, including names, dates of birth, and addresses. This dataset was then used to populate and test our two primary data structures: a linked list and a binary search tree.

We focused on evaluating and comparing the performance of these data structures by analyzing the run times for various operations such as adding, deleting, searching, and updating student records. The linked list, with its straightforward node-based structure, allowed us to implement efficient traversal and update operations. Conversely, the binary search tree provided faster search and retrieval times due to its hierarchical nature. This hands-on approach deepened our understanding of how different data structures impact performance and the trade-offs involved in their usage.

# How to Run

Run this command : make

then run : ./a.out

# Portions

Python Faker Library, Linked List, Binary Search Tree, Run Time Analysis, Comparison Analysis

# Contributions:

Ryan Ghandour
Linked List Portion:
The linked list class comprised of using a struct to create our Nodes, while using a class to set up our Linked List. Its functionality includes having a default constructor, a add, delete, search, based on both name and ID, display, and finally a update info function. These functions were implemented in the H file and then the functionality is present in the CPP file. The code mainly uses pointers to traverse throughout the singly linked list by using the next pointer which is a member of our struct. This allows us to minimize our runtime and make sure it is as efficient as possible without using an excess amount of four loops or if statements which will increase the runtime of each of the functions leading to a less efficient algorithm. The search function is present for both name and ID as specified in the requirements due to the possibility of an ID not being present for an individual therefore searching by name would be the only other solution. Our delete function uses the ID of the student as one of its parameters thereby allowing us to iterate through and delete the specified person. Our update info function is where we allow the user to alter already present information for any individual in the list and we give them the functionality of choosing whatever personal information they would like to alter or change.
