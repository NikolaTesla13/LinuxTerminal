#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
ifstream read("data.in");
ofstream write("data.in", ios_base::app);


void about()
{
	cout << "TerminalS v0.1 BETA\n";
}


void check(char msg[1000])
{
	if (strcmp(msg,"about")==0)
		about();
	else
		if (strcmp(msg,"exit")==0)
			system("pause");
		else
			system(msg);
}


void create_user()
{
	string usr1, pwd1;
	cout << "Your username will be: ";
	cin >> usr1;
	cout << "\nYour password will be: ";
	cin >> pwd1;

	write << usr1 << " " << pwd1 << endl;
}
char msg[1000];
string ver,usr,pwd,ac;
int main()
{
	//system("Color 0A");
	cout << "Do you have an account? y/n\n";
	cin >> ac;
	if (ac == "n") {
		create_user();
		while (strcmp(msg,"exit")!=0)
		{
			
			cout << ">> ";
			cin >> msg;
			check(msg);
		}
	}
	if(ac == "y")
	{
		cout << "Username: ";
		cin >> usr;
		cout << "\nPassword: ";
		cin >> pwd;
		while (getline(read, ver))
			if (usr + " " + pwd != ver)
				cout << "";
			else
				while (strcmp(msg, "exit") != 0)
				{
					cout << ">> ";
					cin >> msg;
					check(msg);
				}
	}
	read.close();
	write.close();
	return 0;
}
