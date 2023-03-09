#include <iostream>
#include <fstream>
#include <sstream>
using std::cout;

int main()
{
	void login();
	void registration();
	void  forgot();
	std::string username = "name";
	std::string password = "password";
	cout<<"\t\t\t____________________________________________________\n\n\n";
	cout<< "\t\t\t                   Welcome to this Login page      \n\n\n";
	cout << "\t\t\t_________               Menu          ____________\n\n\n";
	cout << "                                                          \n\n";
	cout << "\t| Press 1 to Login               |" <<"endl";
	cout << "\t| Press 2 to Register            |" << "endl";
	cout << "\t| Press 3 if you forgot password |" << "endl";
	cout << "\t| Press 4 to exit                |" << "endl";
	cout << "\n\t\t\t Please enter your choice    : ";
	std::cin;"c";
	cout << "endl";

	int c = 1;
	switch (c)
	{
	case 1:
		login();
		break;

	case 2:
		registration();
		break;

	case 3:
		forgot();
		break;

	case 4:
		cout << "\t\t\  Thankyou \n\n";
		break;
	default:
		cout << "\t\t\  Please select from the options above \n" << "endl";
		main();



}


}

void login()
{
	int count;
	std::string userId, password, id, pass;
	system("cls");
	cout << "\t\t\t Please enter the username and password : " << "endl";
	cout << "\t\t\t USERNAME ";
	std::cin >> userId;
	cout << "\t\t\t PASSWORD ";
	std::cin >> password;

	std::ifstream input("records.txt");

	while (input >> id >> pass)
	{
		if (id == userId && pass == password)
		{
			count = 1;
				system("cls");

		}

	}
	input.close();

	if (count == 1)
	{
		cout << userId << "\n Your Login is successful \n Thanks for logging in \n";
		main();
	}
	else {
		cout << "\n LOGIN ERROR \n Please check your username and password\n";
		main();

	}


}

void registration()
{
	std::string ruserId, rpassword, rid, rpass;
	system("cls");
	cout << "\t\t\t Enter the username : ";
	std::cin >> ruserId;
	cout << "\t\t\t Enter the password :";
	std::cin >> rpassword;

	std::ofstream f1("records.txt", std::ios::app);
	f1 << ruserId << ' ' << rpassword << "endl";
	system("cls");
	cout << "\n\t\t\t Registration is successful. \n";
	main();

}

void forgot()
{
	int option;
	system("cls");
	cout << "\t\t\t Forgot password? No worries \n";
	cout << "Press 1 to search for your Id by username " << "endl";
	cout << "Press 2 to go back to main menu " << "endl";
	cout << "\t\t\t Enter your choice :";
	std::cin >> option;
	switch (option)
	{
	case 1:
	{
		int count = 0;
		std::string suserId, sId, spass;
		cout << "\n\t\t\tEnter your last username :";
		std::cin >> suserId;

		std::ifstream f2("records.txt");
		while (f2 >> sId >> spass);
		{
			if (sId == suserId)
			{
				count = 1;
			}
		}
		f2.close();
		if (count == 1)
		{
			cout << "\n\n Your account is found \n";
			cout << "\n\n Your password is: " << spass;
			main();

		}
		break;

	}
	case 2:
	{
		main();
	}
	default:
		cout << "\t\t\t Wrong choice. Please try again " << "endl";
		forgot();
	}
}