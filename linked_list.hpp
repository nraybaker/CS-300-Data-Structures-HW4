/*******************************************************************************
	Author: Nathan Baker
	Student ID: A767P375
	Program: #4
	 
	 
	Psuedo Code:
	Class Name: Linked_list
	 
		Data:
			head pointer - will point to first Node in list
			trail pointer - will point to last Node in the list
			count - keeps track of the number of Nodes in the list
		 
		Class Functions:
			
			Function: Linked_list
				Default contructor
				Input: None
				Output: None
				Return: NA 
					Just creates list will null pointers and count 0
			
			Function: insert_node
				Insert a node into the linked list
				Input: Title, author, day, month, year
				Output: None
				Return: N/A 
					Inserts a node into the list
				
			Function: delete_node
				Delete a Node from the linked list
				Input: Book title to delete from the list
				Output: N/A
				Return: true if successful, false if unsuccessful (or node not
					found)
					Deletes the Node with the matching title from the list
				
			Function: traverse_forward
				Traverse the list forwards from head to tail
				Input: None
				Output: Print all of the list from head to tail
				Return: true if successful, false if unsuccessful
			
			Function: traverse_backward
				Traverse backwards from tail to head printing
				Input: None
				Output: Print all of the list from tail to head
				Return: true if successful, false if unsuccessful

			Function: retrieve
				Retrieve a node that matches a title
				Input: Title
				Output: Print the data associated with that title
				Return: true if successful, false if unsuccessful (or no
					node with a match to the title)
				
			Function: file_write
				Write list data to a file called booklist.txt
				Input: N/A
				Output: N/A
				Return: N/A | Deletes any files called booklist.txt and
					writes entire list to a new file called booklist.txt
*/
#include <iostream>


using namespace std;

//Linked_list will be a double linked list
class Linked_list
{
	int count;
	Node *head;
	Node *tail;
	
public:
	//Default constructor to create list
	Linked_list();
	
	//Insert a new node into the list
	//Unordered list to node is inserted at the end
	void insert_node(string ttl, string auth, int month, int day, int year);
	
	//Deletes node from list that matches title input
	bool delete_node(string ttl);
	
	//Traverses list from head to tail printing contents
	bool traverse_forward();
	
	//Traverses list from tail to head printing contents
	bool traverse_backward();
	
	//Retrieves a node from the list and prints the contents
	bool retrieve(string ttl);
	
	//Writes the contents of entire list to a file called booklist.txt
	void file_write();
};


