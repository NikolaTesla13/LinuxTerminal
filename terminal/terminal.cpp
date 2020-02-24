#include <bits/stdc++.h>


using namespace std;
ifstream read("data.in");
ofstream write("data.in", ios_base::app);




#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */



char msg[1000];
string ver,usr,pwd,ac;

void about()
{
	cout << "TerminalS v0.1 BETA\n";
}

void dev_help()
{
    cout<< RED << "DEVELOPER HELP\n";
    cout<< BOLDYELLOW << "HOW TO BUILD\nEVERYTHING\n\n";
    cout<< WHITE << "g++ - C++\npython3 - Python\ngcc - C\njava - Java\nflutter run - Flutter\n\n";
}

void nav_help()
{
    cout<< RED << "NEWBIE HELP TO TERMINAL\n";
    cout<< BOLDYELLOW << "HOW TO USE\nIT\n\n";
    cout<< WHITE << "cd folder - navigate to the folder\npwd - show the path\nmkdir folder - make a new folder\ncd .. - navigate one level down\ntouch file - create file\nls - show the file in the currend directory\n\n";
}

void check(char msg[1000])
{
	if (strcmp(msg,"about")==0)
		about();
	else
		if (strcmp(msg,"dev-help")==0)
			dev_help();
        else
            if (strcmp(msg,"help")==0)
                nav_help();
		else
			system(msg);
}


void terminal()
{
	string pwd = "";
	while (strcmp(msg,"exit")!=0)
	{
        cout<< CYAN;
		pwd = system("pwd");
		cout << CYAN << pwd << CYAN<< "$  " << GREEN;
		cin.getline(msg, 100);
		check(msg);
	}
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

void login()
{
    cout << "Do you have an account? y/n\n";
        cin >> ac;
        if (ac == "n") {
            create_user();
            terminal();
        }
        if(ac == "y")
        {
            cout << "Username: ";
            cin >> usr;
            cout << "\nPassword: ";
            cin >> pwd;
            while (getline(read, ver))
                if (usr + " " + pwd != ver)
                    ;
                else
                    terminal();
        }
}

void debug()
{
	while (strcmp(msg,"exit")!=0)
	{
		cin.getline(msg, 100);
		cout<<endl;
		cout<<msg;
	}
}
int main()
{
    //login() USELESS
	terminal();
	//debug();
	read.close();
	write.close();
	return 0;
}
