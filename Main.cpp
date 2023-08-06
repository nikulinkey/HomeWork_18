#include "Message.h"
#include "User.h"
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;
using namespace std;

int main()
{
	char choise = 0;
	while (choise != 'q')
	{
		cout << "choose option: " << endl;
		cout << "1 - write message" << endl << "2 - read messages" << endl;
		cout << "3 - create user" << endl << "4 - show users" << endl;
		cout << "q - quit" << endl;
		cin >> choise;
		switch (choise) {
		case '1':
		{
			string text, sender, receiver;
			cout << "enter sender: " << endl;
			cin >> sender;
			cout << "enter receiver: " << endl;
			cin >> receiver;
			cout << "enter message: " << endl;
			cin >> text;

			fstream mess_file = fstream("messages.txt", ios::in | ios::out);
			fs::permissions("messages.txt", fs::perms::owner_all, fs::perm_options::add);
			fs::permissions("messages.txt", fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);

			if (!mess_file)
				mess_file = fstream("messages.txt", ios::in | ios::out | ios::trunc);

			if (mess_file) {
				Message newMessage(text, sender, receiver);
				mess_file << newMessage << endl;
				break;
			}
			else
			{
				cout << "Could not open file messages.txt !" << '\n';
				break;
			}
		}
		case '2':
		{
			fstream mess_file = fstream("messages.txt", ios::in | ios::out);

			if (mess_file) {
				Message Message("a", "b", "c");
				mess_file.seekg(0, ios_base::beg);
				// —читываем данные из файла
				mess_file >> Message;
				cout << Message << endl;
				break;
			}
			else
			{
				cout << "Could not open file messages.txt !" << '\n';
				break;
			}
		}
		case '3':
		{
			string name, login, pass;
			cout << "enter name: " << endl;
			cin >> name;
			cout << "enter login: " << endl;
			cin >> login;
			cout << "enter password: " << endl;
			cin >> pass;

			fstream user_file = fstream("users.txt", ios::in | ios::out);
			fs::permissions("users.txt", fs::perms::owner_all, fs::perm_options::add);
			fs::permissions("users.txt", fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);
			if (!user_file)
				user_file = fstream("users.txt", ios::in | ios::out | ios::trunc);

			if (user_file) {
				User newUser(name, login, pass);
				user_file << newUser << endl;
				break;
			}
			else
			{
				cout << "Could not open file users.txt !" << '\n';
				break;
			}
		}
		case '4':
		{
			fstream user_file = fstream("users.txt", ios::in | ios::out);

			if (user_file) {
				User User("a", "b", "c");
				user_file.seekg(0, ios_base::beg);
				user_file >> User;
				cout << User << endl;
				break;
			}
			else
			{
				cout << "Could not open file users.txt !" << '\n';
				break;
			}
		}
		}
	}
	return 0;
}