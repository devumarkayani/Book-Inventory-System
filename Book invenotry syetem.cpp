//  bookshop inventory system
#include <fstream> 
#include <iostream>
using namespace std;
////////////////////////
// Function to display the menus
int menu()
{
	system("cls");
	cout << "\n\n\t\t\t\tMENU";
	cout << "\n\n1. ADD BOOK";
	cout << "\n2. DISPLAY BOOKS";
	cout << "\n3. SEARCH PARTICULAR BOOK";
	cout << "\n4. UPDATE BOOK";
	cout << "\n5. DELETE BOOK";
	cout << "\n6. EXIT";
}
/////
// Function to add book
int add_book()
{
	system("cls");
	int no_copy;
	string b_name, a_name, b_id;
	cout << "\n\n\t\t\t\tADD BOOKS";
	cout << "\n\nEnter Book ID : ";
	getline(cin,b_id);
	cout << "\nEnter Book Name : ";
	getline(cin,b_name);
	cout << "\nEnter Author Name : ";
	getline(cin,a_name);
	cout << "\nEnter No. of Books : ";
	cin >> no_copy;
    cin.ignore();
	
	// Open file in append
	ofstream file("C://book.txt",ios::app);
    			
    file << b_id<< "\t"<< b_name<< "\t"<< a_name<< "\t"<< no_copy<<"\n";
}
////////
// Function to display book
show_book()
{
	system("cls");
	int no_copy;
	string b_name, b_id, a_name;
	cout << "\n\n\t\t\t\t\tAll BOOKS";

	// Open the file in input mode for read the data
	ifstream file("C://book.txt");
	
	if (!file)
	  {

		cout << "\n\nFile Opening Error!";
      }
	else 
	{

		cout << "\n\n\nBook ID\t\tBook\t\tAuthor\t\tNo. of Books\n\n";
		
		file >> b_id >> b_name;
		file >> a_name >> no_copy;

		// Till end of file is reached
		while (!file.eof()) 
		{
              
		  cout << " " << b_id<< "\t\t" << b_name<< "\t\t" << a_name<< "\t\t" << no_copy<< "\n\n";
			file >> b_id >> b_name;
			file >> a_name >> no_copy;
		} 

		system("pause");

		// Close the file
		file.close();
	}
}
///////////
// Function to check the book
check_book()
{
	system("cls");
	int no_copy, count = 0;
	string b_id, b_name, a_name, b_idd;

	cout << "\n\n\t\t\t\tSearch A Book";
	// Open the file in input mode
	ifstream file("C://book.txt");
	if (!file)
		cout << "\n\nFile Opening Error!";
	
		else {

		cout << "\n\nEnter Book ID for the Book you want to find : ";
		cin >> b_idd;
		cin.ignore();
		file >> b_id >> b_name;
		file >> a_name >> no_copy;

		while (!file.eof()) 
		{
			if (b_idd == b_id) 
			{
     			system("cls");
				cout << "\n\n\t\t\t\t Book Found..!!!";
				cout << "\n\nBook ID : "<< b_id;
				cout << "\nName : "<< b_name;
				cout << "\nAuthor : "<< a_name;
				cout << "\nNo. of Books : "<< no_copy;
				cout << endl<< endl;
				count++;
				break;
			}
			file >> b_id >> b_name;
			file >> a_name >> no_copy;
		}
		
		if (count == 0)
		cout << "\n\n\t\tSorry Book ID is Not Found...\n";	
		
		system("pause");
		file.close();
		
	}
}
//////////
// Function to update the book
update_book()
{
	system("cls");
	int no_copy, no_co, count = 0;
	string b_name, b_na, a_name;
	string a_na, b_idd, b_id;
	cout << "\n\n\t\t\t\tUpdate Book Record";
	ofstream file_w("C://book1.txt");
	ifstream file_r("C://book.txt");
	if (!file_r)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nEnter Book ID of book you want to update : ";
		cin >> b_id;
		cin.ignore();
		file_r >> b_idd >> b_name;
		file_r >> a_name >> no_copy;
	// Till end of file is reached
		while (!file_r.eof()) 
		{
			if (b_id == b_idd)
			 {
				system("cls");
				cout << "\t\t\t\t Update Book Record";
				cout << "\n\nPlease Enter New Book Name : ";
				getline(cin,b_na);
				cout << "\nPlease Enter Author Name : ";
				getline(cin, a_na);
				cout << "\nPlease Enter No. of Books : ";
				cin >> no_co;
				cin.ignore();
				file_w << " " << b_id << " "<< b_na << " "<< a_na 
				<< " " << no_co<< "\n\n";
				count++;
			}
			else
			{
				file_w << " " << b_idd
					<< " " << b_name
					<< " " << a_name
					<< " " << no_copy
					<< "\n\n";
			}
			
			file_r >> b_idd >> b_name;
			file_r >> a_name >> no_copy;
		}
		if (count == 0)
			cout << "\n\nSorry Book ID is Not Found...";
	}
	cout << endl;
	system("pause");
	// Close the files
	file_w.close();
	file_r.close();
	remove("C://book.txt");
	rename("C://book1.txt",
		"C://book.txt");
}
//////////
// Function to delete book
del_book()
{
	system("cls");
	int no_copy, count = 0;
	string b_id, b_idd, b_name, a_name;
	cout << "\n\n\t\t\t\tDelete a Book";
	// Append file in output mode
	ofstream file_w("C:// book1.txt");
	ifstream file_r("C:// book.txt");
	if (!file_r)
		cout << "\n\nFile Opening Error...";
	else {
    	cout << "\n\nEnter Book ID of book you want to delete: ";
		cin >> b_id;
		file_r >> b_idd >> b_name;
		file_r >> a_name >> no_copy;
		while (!file_r.eof()) 
		{
			if (b_id == b_idd) 
			{
			  system("cls");
				cout << "\n\n\t\t\t\t"
					<< "Delete a Book";
				cout << "\n\nBook is Deleted "
						"Successfully with the id = "<<b_id<<"\n\n";
				count++;
			}
			else
			{
				file_w << " " << b_idd<< " " << b_name<< " " << a_name
					<< " " << no_copy
					<< "\n\n";
		    }
			file_r >> b_idd >> b_name;
			file_r >> a_name >> no_copy;
		}
		if (count == 0)
			cout << "\n\nBook ID  Not Found...";
	}
	system("pause");

	// Close the file
	file_r.close();
	file_w.close();
	remove("C://book.txt");
	rename("C://book1.txt", "C://book.txt");
}
/////
// Function for book shop record
void BSIS()
{
	int choice;
	char ch;
	
	while (1) 
	{
		menu();
		cout << "\n\nEnter your choice : ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		 {

		case 1:
			do {

				add_book();
				cout << "\n\nWant to add another book? (y/n) : ";
					cin >> ch;
				cin.ignore();
			   } while (ch == 'y' || ch=='Y');
			break;

		case 2:
			show_book();
			break;

		case 3:
			check_book();
			break;

		case 4:
			update_book();
			break;

		case 5:
			del_book();
			break;

		case 6:
			exit(1);
			break;
		default:
			cout << "\n\nINVALID CHOICE\n";
		}
	}
}
/////////////////////////
int main()
{
	BSIS();

	return(0);
}

