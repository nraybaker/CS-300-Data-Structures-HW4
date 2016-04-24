/***************************************************************************
	Author: Nathan Baker
	Student ID: A767P375
	Program: #4
*/
#include "node.cpp"
#include "linked_list.cpp"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	//Create default linked list
	Linked_list book_list;
	
	//Try and open file booklist.txt
	ifstream infile;
	infile.open("booklist.txt");
	
	//If the file is not good (doesn't exist) will write a new booklist.txt file
	if(!infile.good())
	{
		cout << "WARNING: booklist.txt File Not Found" << endl;
		cout << "Writing new booklist.txt file" << endl << endl;
	}
	
	//Else write contents of file into book_list
	else
	{
		cout << "booklist.txt file found; writing to list" << endl << endl;
		//While not at the end of file continue writing contents to book_list
		while(!infile.eof())
		{
			string title, author;
			int month, day, year;
			getline(infile, title); 
			getline(infile, author);
			infile >> month;
			infile >> day;
			infile >> year;
			infile.ignore();
			book_list.insert_node(title, author, month, day, year);
		};
		infile.close();
	};
	
	//state to control when menu exits
	bool state = true;
	
	do
	{
		//Setting up menu options
		int option;
		do
		{
			//Creating menu with options
			cout << "Options: " << endl;
			cout << "Press 1 to Add a Book" << endl;
			cout << "Press 2 to Delete a Book" << endl;
			cout << "Press 3 to Retrieve a Book" << endl;
			cout << "Press 4 to Traverse Backwards and Print" << endl;
			cout << "Press 5 to Traverse Forwards and Print" << endl;
			cout << "Press 6 to Exit" << endl;
			cin >> option;
			if(!((option == 1) | (option == 2) | (option == 3) | (option == 4) | (option == 5) | (option == 6)))
			{	
				cout << "Invalid option; Please choose an integer from 1 to 5: " << endl << endl;
			};
		} while(!((option == 1) | (option == 2) | (option == 3) | (option == 4) | (option == 5) | (option == 6)));
		
		cout << endl << "You choose option: " << option << endl;
		
		switch(option)
		{
			//Case 1: read input and insert into book_list
			case 1 :
			{
				string title, author;
				int month, day, year;
				cout << "Enter a Book Title: ";
				cin.ignore();
				getline(cin, title);
				
				
				cout << endl << "Enter the Author: ";
				getline(cin, author);
				
				
				cout << endl << "Enter the Month Read: ";
				cin >> month;
				
				cout << endl << "Enter the Day Read: ";
				cin >> day;
				
				cout << endl << "Enter the Year Read: ";
				cin >> year;
				
				book_list.insert_node(title, author, month, day, year);
				break;
			}
			
			//Case 2: Read title to delete and delete a book with that title
			case 2 :
			{
				string title;
				cout << "Enter Title to Delete: ";
				cin.ignore();
				getline(cin, title);
				
				//If book is not found will output this message
				//Else it will output the contents associated with the book
				bool found = book_list.retrieve(title);
				if(!found)
				{
					cout << "Book Not Found." << endl << endl;
				}
				
				else
				{
				
					bool state2 = true;
					do
					{
						//Option to confirm a delete
						char confirm;
						cout << "Confirm Delete (Y/n): ";
						cin >> confirm;
						
						//Deletes book from list if Y or y
						if((confirm == 'Y') || (confirm == 'y'))
						{
							book_list.delete_node(title);
							cout << "Titles deleted from list." << endl << endl;
							state2 = false;
						}
						
						//Does not delete if N or n entered
						else if((confirm == 'N') || (confirm == 'n'))
						{
							cout << "Titles not deleted from list." << endl << endl;
							state2 = false;
						}
						
						//Repeats confirm selection if something unknown entered
						else
						{
							cout << "Error: Unknown Entry; Please enter Y or n";
						}
					} while(state2);
				}
				break;
			}
			
			//Case 3: Retrieves the contents of the book associated with the title
			case 3 :
			{
				string title;
				cout << "Enter title to retrieve: ";
				cin.ignore();
				getline(cin, title);
				
				//If book not found shows this output
				bool found = book_list.retrieve(title);
				if(!found)
					cout << "Book Not Found." << endl;
					
				cout << endl;
				break;
			}
			
			//Case 4: Traverse the list from tail to head printing the contents
			case 4 :
			{
				book_list.traverse_backward();
				cout << endl;	
				break;
			}
			
			//Case 5: Traverse the list from head to tail printing the contents
			case 5 :
			{
				book_list.traverse_forward();
				cout << endl;
				break;
			}
			
			//Case 6: Exit the option menu
			case 6 :
			{
				state = false;
				break;
			}
		}	
	} while(state);
	
	//Calls function to write list to file
	//Did not do this in main since I could not access node data outside of
	//the Linked_list class
	cout << "Writing List to booklist.txt" << endl;
	book_list.file_write();
	
	return(0);
}


