/***************************************************************************
	Author: Nathan Baker
	Student ID: A767P375
	Program: #4
*/
#include "node.hpp"
#include <iostream>
using namespace std;

//Default constructor with favorite book
Node::Node()
{
	title = "Dune";
	author = "Frank Herbert";
	day = 14;
	month = 2;
	year = 2016;
	next_link_ptr = NULL;
	prev_link_ptr = NULL;
}

//Non-default constructor
Node::Node(string ttl, string auth, int mo, int d, int y)
{
	title = ttl;
	author = auth;
	month = mo;
	day = d;
	year = y;
	next_link_ptr = NULL;
	prev_link_ptr = NULL;
}

//Set the next_link_ptr to point to next Node
void Node::set_next_link(Node *ptr)
{
	next_link_ptr = ptr;
}

//Set the prev_link_ptr to point to prev. Node
void Node::set_prev_link(Node *ptr)
{
	prev_link_ptr = ptr;
}


//Return the memory location of the next link to the current Node
Node *Node::get_next_link()
{
	return(next_link_ptr);
}

//Return the memory location of the prev. link to the current Node
Node *Node::get_prev_link()
{
	return(prev_link_ptr);
}

//Get the title of the Node
string Node::get_title()
{
	return(title);
}

//Get the author of the Node
string Node::get_author()
{
	return(author);
}

//Get the month of the Node
int Node::get_month()
{
	return(month);
}

//Get the day of the Node
int Node::get_day()
{
	return(day);
}

//Get the year of the Node
int Node::get_year()
{
	return(year);
}

//Compare the title of the Node with some title passed in
bool Node::compare_title(string ttl_compare)
{
	if(title == ttl_compare)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

//Compare the author of the Node with some author passed in
bool Node::compare_author(string auth_compare)
{
	if(author == auth_compare)
		return(true);
	else
		return(false);
}

//print the data contained in the Node
void Node::process_data()
{
	cout << title << " | " << author << " | " << month << "/" << day << "/" << year << endl;
}


