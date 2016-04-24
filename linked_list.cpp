/***************************************************************************
	Author: Nathan Baker
	Student ID: A767P375
	Program: #4
*/
#include "linked_list.hpp"

#include <iostream>
#include <fstream>
using namespace std;

//Default Linked_list constructor
Linked_list::Linked_list()
{
	count = 0;
	head = NULL;
	tail = NULL;
}

//Inserts a node at end of list since list is unordered
void Linked_list::insert_node(string title, string author, int month, int day, int year)
{
	//Create node with given contents
	Node *node_ptr = new Node(title, author, month, day, year);
	
	//If list is empty set head and tail to point to the new node
	//Node's next and previous link still NULL
	if(count == 0)
	{
		head = tail = node_ptr;
		count++;
	}
	
	//If the list has 1 node already, set next link of head to new node
	//Set previous link of new node to point to the head
	//Set tail to point to the new node
	else if(count == 1)
	{
		head -> set_next_link(node_ptr);
		node_ptr -> set_prev_link(head);
		tail = node_ptr;
		count++;
	}
	
	//If more than 1 node already in list, insert new node at end of list
	//set next link of tail to point to the new node
	//set the prev link of the new node to point to the current tail
	//update tail to point to the new node
	else
	{
		tail -> set_next_link(node_ptr);
		node_ptr -> set_prev_link(tail);
		tail = node_ptr;
		count++;
	}	
}

//Deletes a node with a title matching the given string
bool Linked_list::delete_node(string ttl)
{
	//create curr and prev nodes and set them equal to head of list
	//temp is used later
	Node *prev, *curr, *temp;
	
	curr = head;
	prev = head;
	
	//while curr isn't NULL and the title of curr doesn't match the title given
	//keep moving prev and curr down the list
	while((curr != NULL) && !(curr -> compare_title(ttl)))
	{
		prev = curr;
		curr = curr -> get_next_link();
	}	 
	
	//if curr is NULL then a Node with matching title was not found so return false
	if(curr == NULL)
		return(false);
	
	//Else delete the curr node	
	else
	{
		if(curr == head)
		{
			//If deleting node leaves list empty, set head and tail to NULL
			if(count == 1)
			{
				head = NULL;
				tail = NULL;
				delete curr;
			}
			//else delete curr node by setting head to next link after curr and delete
			else
			{
				head = curr -> get_next_link();
				head -> set_prev_link(NULL);
				delete curr;
			}
		}	
		
		
		else
		{
			//if curr is that tail set prev node next link to NULL and move
			//tail back to prev node then delete
			if(curr == tail)
			{
				prev -> set_next_link(NULL);
				tail = prev;
				delete curr;
			}
			
			//else set temp equal to the link after curr. set next link of prev
			//to point to temp and set prev link of temp to point to prev
			//then delete
			else
			{
			
				temp = curr -> get_next_link();
				prev -> set_next_link(temp);
				temp -> set_prev_link(prev);
				delete curr;
			}
		}
		count--;
	}
	return(true);
}

//Traverse the list from head to tail printing
bool Linked_list::traverse_forward()
{
	//temp starts at head and will move down the list
	Node *temp;
	temp = head;
	
	//If list is empty then print the following
	if(temp == NULL)
	{
		cout << "No books in list." << endl;
		return(0);
	}
	
	//temp isn't at the end of the list continue printing the data
	while(temp != NULL)
	{
		temp -> process_data();
		
		temp = temp -> get_next_link();
	}
	return(1);
}

//Traverse the list from tail to head printing
bool Linked_list::traverse_backward()
{
	//temp starts at tail and moves up the list
	Node *temp;
	temp = tail;
	
	//if list is empty then print the following
	if(temp == NULL)
	{
		cout << "No books in list." << endl;
		return(0);
	}
	
	//else continue printing up the list until it reaches past the head
	while(temp != NULL)
	{
		temp -> process_data();
		
		temp = temp -> get_prev_link();
	}
	return(1);
}

//Retrieve a node from the list matching the title
bool Linked_list::retrieve(string ttl)
{
	//temp starts at head and moves down trying to find the title
	Node *temp;
	temp = head;
	int index = 0;
	while(temp != NULL)
	{
		if(temp -> compare_title(ttl))
		{
			temp -> process_data();
			index++;
		}
		temp = temp -> get_next_link();
	}
	
	//if index is still = 0 then the title was not found
	if(index != 0)
		return(1);
		
	else
		return(0);
}

//write the entire contents of the list to a file called booklist.txt
void Linked_list::file_write(void)
{
	//start temp at head and move down the list
	Node *temp;
	temp = head;
	
	//output file
	ofstream outfile;
	outfile.open("booklist.txt", ios::trunc);
	
	//write the list to the outfile
	while(temp != NULL)
	{
		if(temp == tail)
		{
			outfile << temp -> get_title() << endl;
			outfile << temp -> get_author() << endl;
			outfile << temp -> get_month() << endl;
			outfile << temp -> get_day() << endl;
			outfile << temp -> get_year();
			temp = NULL;
		}
		else
		{
			outfile << temp -> get_title() << endl;
			outfile << temp -> get_author() << endl;
			outfile << temp -> get_month() << endl;
			outfile << temp -> get_day() << endl;
			outfile << temp -> get_year() << endl;
			temp = temp -> get_next_link();
		}
	}
	
	//close the outfile
	outfile.close();
}


