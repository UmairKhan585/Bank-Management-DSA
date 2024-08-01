//      ------------------------------------    
//      |   Libraries To Start The Project  |
//      ------------------------------------ 

#include<iostream>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
#include<string>

using namespace std;

int depositbalance;
int withdrawal;

//      ------------------------------------
//      |        Creating Manager End       |
//      ------------------------------------

struct manager
{
	long int manid = 99999;
	int pinnn = 1234;
};

//      ------------------------------------
//      |        Creating Link-List         |
//      ------------------------------------

struct node
{
	long int id_number;
	int atm_number;
	string name;
	string fathername;
	int pin;
	int initialbalance;
	int counternum;
	node* next;
};

node* head = NULL;
node* tail = NULL;
int counter = 0;
int counterrandom = 0;
long int atmnum = 10000;
long int bankvault = 0;


//      ------------------------------------
//      |   Function To create new Account  |
//      ------------------------------------

void newaccount(node* head)
{
	counterrandom++;
	string answer;
	node* temp = new node;
	temp->counternum = counter++;
	cout << "ENTER YOUR NAME: ";
	cin >> temp->name;
	cout << "Enter your father name:";
	cin >> temp->fathername;
	cout << "Enter your national ID card Number:";
	cin >> temp->id_number;
	cout << "Do you want to deposit money right now ?" << endl;
	cin >> answer;
	if (answer == "Yes" || answer == "yes" || answer == "YES")
	{
		cout << "Enter the amout you want to deposit :";
		cin >> temp->initialbalance;
		bankvault += temp->initialbalance;
	}
	cout << "SET YOUR NEW 4 DIGIT PIN";
	int pin = 0;
	cin >> temp->pin;
	while (temp->pin < 999 || temp->pin > 9999)
	{
		cout << "SELECT PIN ONLY OF 4 DIGITS";
		cin >> temp->pin;
	}
	atmnum += 1;
	temp->atm_number = atmnum;
	if (head == NULL) {
		temp->next = NULL;
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
		tail->next = NULL;
	}
	cout << "YOUR ACCOUNT NUMBER IS: " << temp->atm_number;
	
}

//      -----------------------------------------------
//      |   Function for depositing Amount from user  |
//      -----------------------------------------------

int depositcash(node* headd)
{
	node* temp;
	int atm_number;
	int pin;
	temp = head;
	cout << "ENTER YOUR ATM NUMBER : ";
	cin >> atm_number;
	cout << "PIN: ";
	cin >> pin;
	while (temp != NULL)
	{
		if (atm_number == temp->atm_number && pin == temp->pin)
		{
			cout << "Enter the amout you want to deposit:";
			cin >> depositbalance;
			temp->initialbalance = temp->initialbalance + depositbalance;
			bankvault += depositbalance;
			cout << "Your amount is deposited !!" << endl;
			break;
		}
		temp = temp->next;
	}
	if (temp == NULL)
	{
		cout << "DOES NOT MATCH ANY ACCOUNT ";
		return 0;
	}

}

//      ----------------------------------------------
//      |   Function for withdrawing Amount from user |
//      ----------------------------------------------


void withdrawalaccount(node* head)
{
	node* temp = head;
	int atm_number;
	int pin;
	cout << "ENTER YOUR ATM NUMBER AND NAME: ";
	cin >> atm_number;
	cout << "PIN: ";
	cin >> pin;

	while (temp != NULL)
	{
		if (atm_number == temp->atm_number && pin == temp->pin)
		{
			cout << "Enter the amout you want to withdrawal:";
			cin >> withdrawal;
			if (temp->initialbalance > withdrawal){
				temp->initialbalance = temp->initialbalance - withdrawal;
				bankvault -= withdrawal;
				cout << "The amount is withdrawaled from the Account !!" << endl;
				break;
			}
		}
		else
		{
			cout << "YOU DONT HAVE SUFFICIENT BALANCE FOR THIS WITHDRAWAL";
		}
		temp = temp->next;
	}
	if (temp == NULL)
	{
		cout << "DOES NOT MATCH ANY ACCOUNT ";
	}
}

//      ----------------------------------------------------
//      |        Function for Total Balance Enquiry         |
//      ----------------------------------------------------


void balancecheck(node* head)
{
	node* temp = head;
	int atm_number;
	int pin;
	cout << "ENTER YOUR ATM NUMBER AND NAME: ";
	cin >> atm_number;
	cout << "PIN: ";
	cin >> pin;
	while (temp != NULL)
	{
		if (atm_number == temp->atm_number && pin == temp->pin)
		{
			cout << "Your Account Balance is :";
			cout << temp->initialbalance;
		}

		temp = temp->next;
	}
	if (temp == NULL)
	{
		cout << "Account not found !!" << endl;
	}
}

void deletefirstaccount(node* head)
{
	cout << "Your amount :";
	cout << head->initialbalance;
	head = head->next;
}

void delete_last(node* head)
{
	node* current = new node;
	node* previous = new node;
	current = head;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	cout << "Your Amount is :";
	cout << current->initialbalance;
	tail = previous;
	previous->next = NULL;
	delete current;
}


void deletespecificaccount(node* head, int pos)
{
	node* prev = head;
	node* curr = head;

	for (int i = 0; i < pos; i++)
	{
		prev = curr;
		curr = curr->next;
	}
	cout << "Your amount is :";
	cout << curr->initialbalance;
	prev->next = curr->next;
	delete curr;
}

//      --------------------------------------------
//      |       Function for Close An Account      |
//      --------------------------------------------

void accountdelete(node* head)
{
	node* temp = head;
	int atm_number;
	int pin;
	cout << "ENTER YOUR ATM NUMBER AND NAME: ";
	cin >> atm_number;
	cout << "PIN: ";
	cin >> pin;

	while (temp != NULL)
	{
		if (atm_number == temp->atm_number && pin == temp->pin)
		{
			if (temp->counternum == 1)
			{
				deletefirstaccount(temp);
			}
			else if (temp->counternum == counterrandom)
			{
				delete_last(temp);
			}
			else
			{
				deletespecificaccount(temp, temp->counternum);
			}
		}

		temp = temp->next;
	}
	if (temp == NULL)
	{
		cout << "Account not found !!" << endl;
	}
}

//      ------------------------------------------------
//      |        Function for Transfering Cash         |
//      ------------------------------------------------

int cashtransfer(node* head)
{
	int amount;
	node* temp = head;
	cout << "ENTER SENDERS INFO: ";
	int atm_number;
	int pin;
	cout << "ENTER YOUR ATM NUMBER : ";
	cin >> atm_number;
	cout << "PIN: ";
	cin >> pin;

	while (temp != NULL)
	{
		if (atm_number == temp->atm_number && pin == temp->pin)
		{
			cout << "ENTER THE AMOUNT YOU WANT TO SEND:";
			cin >> amount;
			temp->initialbalance = temp->initialbalance - amount;
		}

		temp = temp->next;
	}

	if (temp == NULL)
	{
		cout << "SORRY! WRONG ATM NUMBER OR PIN";
		return 0;
	}
	int rec_atm;
	cout << "ENTER RECEIVER'S ATM NUMBER: ";
	cin >> rec_atm;

	temp = head;
	while (temp != NULL)
	{
		if (atm_number == temp->atm_number)
		{
			cout << " The Amount " << amount << " send to " << temp->name << endl;
			temp->initialbalance = temp->initialbalance + amount;
		}

		temp = temp->next;
	}

	if (temp == NULL)
	{
		cout << "SORRY! WRONG ATM NUMBER.";
		return 0;
	}

}

//      ----------------------------------------------
//      |   Function for Modifying Account            |
//      ----------------------------------------------


void modifyaccount(node* head)
{
	string answer;
	node* temp = head;
	int option;
	int atm_number;
	int pin;
	cout << "ENTER YOUR ATM NUMBER : ";
	cin >> atm_number;
	cout << "PIN: ";
	cin >> pin;

	while (temp != NULL)
	{
		if (atm_number == temp->atm_number && pin == temp->pin)
		{
			cout << " Do you want to modify ?" << endl;
			cin >> answer;
			if (answer == "Yes" || answer == "yes" || answer == "YES")
			{
				cout << "1.Change your existing PIN." << endl;
				cout << "2.Transfer your account to other name." << endl;
				cin >> option;
				switch (option)
				{
				case 1:

					cout << "Enter New PIN:";
					cin >> temp->pin;
					cout << "Your PIN is updated" << endl;
					break;

				case 2:
					cout << "Enter the name you want to transfer your acount:";
					cin >> temp->name;
					cout << "Enter the National ID card number you want to transfer your account:";
					cin >> temp->id_number;
					cout << "Enter father Name:";
					cin >> temp->fathername;
					break;

				}

			}
		}

		temp = temp->next;
	}

	if (temp == NULL)
	{
		cout << "SORRY! WRONG ATM NUMBER.";

	}

}

//      -------------------------------------------
//      |        Function for Giving Loan         |
//      -------------------------------------------

int loanfunction(node *head)
{
	{
		node* temp = head;
		int loan;
		int atm_number;
		int pin;
		cout << "ENTER YOUR ATM NUMBER AND NAME: ";
		cin >> atm_number;
		cout << "PIN: ";
		cin >> pin;
		while (temp != NULL)
		{
			if (atm_number == temp->atm_number && pin == temp->pin)
			{
				cout << "THIS BANK ALLOWS LOAN FROM 1000 Rs to 99999 RS ";
				cout << "ENTER THE AMOUNT OF LOAN YOU WANT TO TAKE:";
				cin >> loan;
				if (loan > 99999 || loan < 1000){
					cout << "SORRY! THIS AMOUNT IS NOT ACCORDING TO THE RULES OF BANK.";
					return 0;
				}
				else{
					cout << loan << "Granted in " << temp->atm_number << " Account";
					temp->initialbalance = temp->initialbalance + loan;

				}
			}

			temp = temp->next;
		}
		if (temp == NULL)
		{
			cout << "Account not found !!" << endl;
		}
	}
}

//      ----------------------------------------------------
//      |        Function for Manager to see History        |
//      ----------------------------------------------------

void managerfunction()
{
	node *temp = head;
	manager t;
	int option;
	int pinn;
	int managerid;
	cout << "...............Manager Login.................. !!" << endl;
	cout << "Please enter your manager ID and pin to login the system !!" << endl;
	cout << "Enter ID:";
	cin >> managerid;
	cout << "Enter PIN:";
	cin >> pinn;
	while (pinn < 999 || pinn > 9999)
	{
		cout << "SELECT PIN ONLY OF 4 DIGITS";
		cin >> pinn;
	}
	if (managerid == t.manid && pinn == t.pinnn)
	{
		cout << "Welcome" << endl;
		cout << "1.Select first option to see total Bank vault Amount !!" << endl;
		cout << "2.Select first option to see total account holder list !" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "The Total Bank Vault Balacnce/Amount is :" << bankvault << endl;
			break;
		case 2:
			cout << "The total accounts in our bank respository is" << endl;
			while (temp != NULL){
				cout << "THE ACCOUNT NUMBER " << temp->counternum << "Details: " << endl;
				cout << "NAME: " << temp->name << endl;
				cout << "CNIC: " << temp->id_number << endl;
				cout << "ATM NUMBER: " << temp->atm_number << endl;
				cout << "TOTAL AMOUNT PRESENT IN THIS ACCOUNT: " << temp->initialbalance << endl;
				temp = temp->next;
			}
			break;
		}
	}

}

//      -----------------------------------------------
//      |          Entery Pont of Project           |
//      -----------------------------------------------


int main()
{
	int choice;
	char  opt;
	string ans;
	cout << endl;
	Sleep(2000);
	cout << "\t\t\t\t\t-----WELCOME!-----" << endl;
	cout << "\t\t\t\t\t\tTO" << endl << endl;

	cout << "DO YOU WISH TO SURVEY MORE:" << endl;
	cin >> ans;

		system("Color 03");
		cout << "\t\t\t\t" << setw(41) << setfill('-') << "-" << endl;
		cout << "\t\t\t\t" << "|" << "\tBAHRIA BANK  LIMITED" << "\t\t|" << endl;
		cout << "\t\t\t\t|\t'Choose your Best'\t\t|" << endl;
		cout << "\t\t\t\t" << setw(41) << setfill('-') << "-" << endl << endl;
		cout << "\t\t\t\t" << setw(41) << setfill('-') << "" << endl;
		cout << "\t\t\t\t" << "|" << "\tMADE BY :: UMAIR MUNIR," << "\t\t|" << endl;
		cout << "\t\t\t\t" << "|" << "\t\t " << "\t\t\t|" << endl;
		cout << "\t\t\t\t" << "|" << "\t\t QIRAB HASSAN " << "\t\t|" << endl;
		cout << "\t\t\t\t" << "|" << "\t\t      &" << "\t\t\t|" << endl;
		cout << "\t\t\t\t" << "|" << "\t\OMAR IKRAM " << "\t\t|" << endl;
		cout << "\t\t\t\t" << setw(41) << setfill('-') << "" << endl << endl;
		Sleep(2000);
		cout << "\t\t\t\t\t\tMain Menu" << endl;
		cout << "\t\t\t\t" << setw(41) << setfill('-') << "-" << endl << endl;

		cout << "\t\t\t\t\tPress 'a' for Manager" << endl;
		cout << "\t\t\t\t\tPress 'b' for Customer" << endl;
		cin >> opt;
		if (opt == 'a')
		{
			managerfunction();
		}
		else if (opt == 'b')
		{
			cout << "\t\t\t\t\t1. Create New Account" << endl;
			cout << "\t\t\t\t\t2. Deposit an Amount" << endl;

			cout << "\t\t\t\t\t3. Withdraw an Amount" << endl;

			cout << "\t\t\t\t\t4. Total Balance Enquiry" << endl;

			cout << "\t\t\t\t\t5. Close an Account" << endl;

			cout << "\t\t\t\t\t6. Transfer Cash" << endl;

			cout << "\t\t\t\t\t7. Modify an Account" << endl;



			cout << "\t\t\t\t\t8. Giving Loan" << endl << endl;
			cout << "\t\t\t\t\t9. Exit" << endl << endl;
			cout << "\t\t\t\t\t->Enter Your's choice : ";
			cin >> choice;

			if (choice == 1)
			{
				newaccount(head);
			}
			else if (choice == 2)
			{
				depositcash(head);
			}
			else if (choice == 3)
			{
				withdrawalaccount(head);
			}
			else if (choice == 4)
			{
				balancecheck(head);
			}

			else if (choice == 5)
			{
				accountdelete(head);
			}

			else if (choice == 6)
			{
				cashtransfer(head);
			}

			else if (choice == 7)
			{
				modifyaccount(head);
			}

			else if (choice == 8)
			{
				loanfunction(head);
			}

			else if (choice == 9)
			{
				cout << "\n\n\tThanks for using bank managemnt system";

			}
			else
			{
				cout << "\t\t\tWrong input" << endl;
			}
			cout << endl;

			cout << "Do you want to continue(yes/no)::"; 
			system("cls");
		}

	} while (ans == "yes" || ans == "YES");
	cin.ignore();
	cin.get();

	_getch();
	return 0;

}












