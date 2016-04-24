/*******************************************************************************
	Author: Nathan Baker
	Student ID: A767P375
	Program: #4
	 
	 
	Description of the problem:
		This program is going to define a preparatory class that you will be
		* using for linked list. You are going to write this class and us it 
		* so that you will be ready to use it for the linked list class.
		* The class is going to be the Node class.

	Psuedo Code:
	Class Name: Node

		Data:
			Book title - string that must hold spaces
			Author - string that must hold spaces
			Date read - int day, month, year
			Pointer I call "next_link" that points ahead to next Node or NULL
			Pointer I call "prev_link" that points behind to previous Node
	
		Mutator Functions:
		
			Function: set_prev_link
				mutator function to set the pointer to the previous node in 
					the list
				Input: where the point should point to
				Outputs: None
				Return: N/A (Just sets the pointer)
				 
			Function: set_next_link
				mutator function to set a pointer to the next node in the
					list or null if at the end
				Input: The node to set the pointer to
				Output: None
				Return: N/A (Just sets the pointer)
			
		
		Accesor Functions:
		
			Funtion: get_prev_link
				Accessor function to access the location of the node "behind"
					the current node that the previous_link pointer is pointing
					to
				Input: None
				Output: None
				Return: Memory location of the node "behind" the current node
					in the list
			
			Function: get_next_link
				Accessor function to access the location of the node "ahead"
					of the current node in the list
				Input: None
				Output: Node
				Return: Memory location of the node "ahead" of current node
			
			Function: get_title
				Accessor function to get the title of the book
				Input: None
				Output: None
				Return:	the book title
		
			Function: get_author
				Accessor function to get the author of the book
				Input: None
				Output: None
				Return: the author
				
			Function: get_month
				Accessor function to get the month the book was read
				Input: None
				Output: None
				Return: the month
				
			Function: get_day
				Accessor function to get the day the book was read
				Input: None
				Output: None
				Return: the day
				
			Function: get_year
				Accessor function to get the year the book was read
				Input: None
				Output: None
				Return: the year
		
		
		Class Functions:
			Function: Node
				Default constructor -- title = favorite book, author = the author,
					date = some date
				Inputs: None
				Outputs: None
				Return: N/A (defaults to above)
		
			Function: Node
				constructor that accepts book title, author, and date
				Inputs: book title, author, date
				Outputs: None
				Return: N/A
					book_title = title passed in
					author = author passed in
					date = date passed in
			
			Function: print_date
				Print the date the book was read
				Input: None
				Output: the date the book was read
				Return: N/A
				
			Function: compare_title
				compare a given book title against the one in the class
				Inputs: a given book title
				Outputs: None
				Return: True if same title, false if not
			 
			Function: compare_author
				Compare a given author against the one in the class
				Inputs: a given author
				Outputs: None
				Return: True if same title, false if not
			
			Function: process_data
				function that will print the data to the screen
				Inputs: None
				Outputs: the data the node contains: title, author, date
				Return: N/A
*/	
#include <iostream>
using namespace std;

//Node class
class Node
{
	//Data for Node class
	string title;
	string author;
	int day, month, year;
	Node *next_link_ptr;
	Node *prev_link_ptr;

public:
	//Default constructor
	Node();
	
	//Non-default constructor
	Node(string ttl, string auth, int mo, int d, int y);
	
	//Set link of the Node to point to previous Node
	void set_prev_link(Node *ptr);
	
	//Set link of the Node to point to Node in front of current Node
	void set_next_link(Node *ptr);
	
	//Get where the previous link in the Node is pointing to
	Node *get_prev_link();
	
	//Get where the next link in the Node is pointing to
	Node *get_next_link();
	
	//Get the title of the Node
	string get_title();
	
	//Get the author of the Node
	string get_author();
	
	//Get the month of the Node
	int get_month();
	
	//Get the day of the Node
	int get_day();
	
	//Get the year of the Node
	int get_year();
	
	//Compare the title of the book with some string
	bool compare_title(string ttl_compare);
	
	//Compare the author of the book with some string
	bool compare_author(string auth_compare);
	
	//Print the data of the Node
	void process_data();
};
