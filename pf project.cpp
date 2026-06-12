#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<windows.h>
#include<ctime>
#include<cstdlib>
using namespace std;
int n = 10;
bool skip = false;
bool skipQuestion = false;
bool extratime = false;
void science(int c,string name,string date);
void History(int c, string name, string date);
void sports(int c, string name, string date);
void computer(int c, string name, string date);
void iq(int c, string name, string date);
void lifeline(char p, int c, string x[], int size); //Function prototype
void setColor(int bg, int fg)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		bg * 6 + fg
	);
}
int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	setColor(1, 5);
	cout << "=====================================\n";
	cout << "=====================================\n";
	SetConsoleTextAttribute(h, 6);
	cout << "       Welcome to Quiz Master       \n";
	setColor(1, 5);
	cout << "=====================================\n";
	cout << "=====================================\n";
	SetConsoleTextAttribute(h, 7);
	cout << endl;
	while (1)
	{
		int choice, catagory, level;
		char op;
		string name, date;
		cout << "1.Start Quiz\n";
		cout << "2.View scores\n";
		cout << "3.Exit game\n";
		cout << "What you want to do:";
		cin >> choice;
		cout << endl;
		if (choice == 1)
		{
			ofstream file;
			file.open("score.txt", ios::app);
			if (!file.is_open())
			{
				cout << "Score file is not opening\n";
			}
			SetConsoleTextAttribute(h, 6);
			cout << "=====================================\n";
			cout << "        -----login page-----         \n";
			cout << "=====================================\n";
			SetConsoleTextAttribute(h, 7);
			cout << "\n";
			cin.ignore();
			cout << "Enter your name: ";
			getline(cin, name);
			cout << "Enter Date: ";
			getline(cin, date);
			cout << "\n";
			SetConsoleTextAttribute(h, 5);
			cout << "=====================================\n";
			SetConsoleTextAttribute(h, 6);
			cout << "        -----Main menu-----          \n";
			SetConsoleTextAttribute(h, 5);
			cout << "=====================================\n";
			SetConsoleTextAttribute(h, 7);
			cout << "1.Science\n2.History\n3.Sports\n4.Computer\n5.IQ\n";
			cout << "Choose catagory:";
			cin >> catagory;
			cout << endl;
			SetConsoleTextAttribute(h, 1);
			cout << "=====================================\n";
			SetConsoleTextAttribute(h, 3);
			cout << "     ---- Difficulty level ----      \n";
			SetConsoleTextAttribute(h, 1);
			cout << "=====================================\n";
			SetConsoleTextAttribute(h, 7);
			cout << "1.Easy\n2.Medium\n3.Hard\n";
			cout << "Enter difficulty level:";
			cin >> level;
			cout << endl;
			if (catagory == 1)
			{
				SetConsoleTextAttribute(h, 11);
				cout << "=====================================\n";
				SetConsoleTextAttribute(h, 14);
				cout << "             Quiz Start              \n";
				SetConsoleTextAttribute(h, 11);
				cout << "=====================================\n";
				SetConsoleTextAttribute(h, 7);
				cout << endl;
				science(level, name, date);
				
			}
			else if (catagory == 2)
			{
				cout << "=====================================\n";
				cout << "             Quiz Start              \n";
				cout << "=====================================\n";
				cout << endl;
				History(level, name, date);
				
			}
			else if (catagory == 3)
			{
				cout << "=====================================\n";
				cout << "             Quiz Start              \n";
				cout << "=====================================\n";
				cout << endl;
				sports(level, name, date);
				
			}
			else if (catagory == 4)
			{
				cout << "=====================================\n";
				cout << "             Quiz Start              \n";
				cout << "=====================================\n";
				cout << endl;
				computer(level, name, date);
				
			}
			else
			{
				cout << "=====================================\n";
				cout << "            Quiz Start               \n";
				cout << "=====================================\n"; 
				cout << endl;
				iq(level, name, date);
				
			}
			
		}
		else if (choice == 2)
		{
			string show;
			ifstream file;
			file.open("score.txt", ios::in);
			if (!file.is_open())
			{
				cout << "File is not open" << endl;
			}
			SetConsoleTextAttribute(h, 11);
			cout << "=====================================\n";
			SetConsoleTextAttribute(h, 10);
			cout << "          ----Scores----           \n";
			SetConsoleTextAttribute(h, 11);
			cout << "=====================================\n";
			SetConsoleTextAttribute(h, 7);
			cout << endl;
			while (getline(file, show))
			{
				cout << show << endl;

			}
		}
		else
		{
			break;
		}
		SetConsoleTextAttribute(h, 11);
		cout << "\ndo you want to play it again (Y/N):";
		SetConsoleTextAttribute(h, 7);
		cin >> op;
		if (op == 'n' || op == 'N')
		{
			SetConsoleTextAttribute(h, 11);
			cout << "=====================================\n";
			SetConsoleTextAttribute(h, 12);
			cout << "           ----Game End----          \n";
			SetConsoleTextAttribute(h, 11);
			cout << "=====================================\n";
			SetConsoleTextAttribute(h, 7);
			break;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
	void science(int c,string name,string date)
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		int points = 0, correct = 0, wrong = 0, consec = 0, number = 1;
		string line[60];
		int questions[10], temp;
		char para = 's';
		if (c == 1)
		{
			char ans, Sans[10] = { 'c','b','b','b','b','c','b','a','b','b' };
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("Escience.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i <10; i++)
			{
				questions[i] = i;
			}
			
			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i+1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp ;
				for (int i= 0; i <60; i++)
				{
					
					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout<< line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{
					
					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
						     
							//Function calling
							lifeline(p,c,line,60);
				
						}
						else
						{
							cout << endl;
							cout << "You entered "<<ans;
							cout << endl;
							break;
						}
					}
				}
				for (static int k = 0; k < 10;)
				{
					
					if (n<0)
					{
						SetConsoleTextAttribute(h, 6);
						cout << "\n=====================================\n";
						cout << "             Times up!!\n";
						cout << "=====================================\n";
						SetConsoleTextAttribute(h, 7);
						points = points - 2;
						break;
					}
					else if (ans == Sans[q])
					{
						SetConsoleTextAttribute(h, 2);
						cout << "=====================================\n";
						cout << "       Great job!Correct answer      \n";
						cout << "=====================================\n";
						SetConsoleTextAttribute(h, 7);
						cout << endl;
						k++;
						correct++;
						points = points + 10;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}
						
						break;
					}
					else
					{
						SetConsoleTextAttribute(h, 4);
						cout << "=====================================\n";
						cout << "           Wrong answer :(\n";
						cout << "=====================================\n";
						SetConsoleTextAttribute(h, 7);
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points -2 ;
						break;
					}
					

				}
			
					if (i + 6 < 60)
					{
						
						cout << endl;
						cout << "Press Enter for next question:\n";
						_getch();
						cout << endl;
					}
				
			}
			
			nfile <<left<< setw(25) <<name<< setw(15)<< date << setw(10)<< correct<< setw(13)<< wrong<< setw(13)<< points<<endl;
			nfile.close();
		}
		if (c == 2)
		{
			char ans, Sans[10] = { 'b','b','c','c','d','c','b','a','a','d' };
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("Mscience.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i < 10; i++)
			{
				questions[i] = i;
			}
			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp;
				for (int i = 0; i < 60; i++)
				{

					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout << line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{

					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
							lifeline(p, c, line, 60);
							
								

						}
						else
						{
							cout << endl;
							cout << "You entered " << ans;
							cout << endl;
							break;
						}
					}

				}
				for (static int k = 0; k < 10;)
				{
					
					if (n < 0)
					{
						cout << "\n-------------------------------\n";
						cout << "         Times up!!\n";
						cout << "-------------------------------\n";
						points = points - 3;
						break;
					}
					
					else if (ans == Sans[q])
					{
						SetConsoleTextAttribute(h, 2);
						cout << "=====================================\n";
						cout << "       Great job!Correct answer      \n";
						cout << "=====================================\n";
						SetConsoleTextAttribute(h, 7);
						cout << endl;
						k++;
						correct++;
						points = points + 15;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}

						break;
					}
					else
					{
						SetConsoleTextAttribute(h, 4);
						cout << "=====================================\n";
						cout << "           Wrong answer :(\n";
						cout << "=====================================\n";
						SetConsoleTextAttribute(h, 7);
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points - 3;
						break;
					}


				}

				if (i + 6 < 60)
				{

					cout << endl;
					cout << "Press Enter for next question:\n";
					_getch();
					cout << endl;
				}

			}
			nfile << left << setw(25) << name << setw(15) << date << setw(10) << correct << setw(13) << wrong << setw(13) << points<<endl;
			nfile.close();
			
		}
		if (c == 3)
		{
			char ans, Sans[10] = { 'b','a','a','d','b','b','c','c','d','b' };
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("Hscience.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i < 10; i++)
			{
				questions[i] = i;
			}
			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp;
				for (int i = 0; i < 60; i++)
				{

					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout << line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{

					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
							lifeline(p, c, line, 60);
							
						}
						else
						{
							cout << endl;
							cout << "You entered " << ans;
							cout << endl;
							break;
						}
					}

				}
				for (static int k = 0; k < 10;)
				{
					
					if (n < 0)
					{
						cout << "\n-------------------------------\n";
						cout << "         Times up!!\n";
						cout << "-------------------------------\n";
						points = points - 5;
						break;
					}
					else if (ans == Sans[q])
					{
						SetConsoleTextAttribute(h, 2);
						cout << "=====================================\n";
						cout << "       Great job!Correct answer      \n";
						cout << "=====================================\n";
						SetConsoleTextAttribute(h, 7);
						cout << endl;
						k++;
						correct++;
						points = points + 25;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}

						break;
					}
					else
					{
						cout << "-------------------------------\n";
						cout << "       Wrong answer :(\n";
						cout << "-------------------------------\n";
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points - 5;
						break;
					}


				}

				if (i + 6 < 60)
				{

					cout << endl;
					cout << "Press Enter for next question:\n";
					_getch();
					cout << endl;
				}

			}
			nfile << left << setw(25) << name << setw(15) << date << setw(10) << correct << setw(13) << wrong << setw(13) << points<<endl;
			nfile.close();
			
		}
		
	}
	void History(int c, string name, string date)
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		int points = 0, correct = 0, wrong = 0, consec = 0, number = 1;
		string line[60];
		int questions[10], temp;

		if (c == 1)
		{
			char ans, Sans[10] = { 'b','b','c','a','b','b','a','b','a','b' }, para = 's';
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("EHistory.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i < 10; i++)
			{
				questions[i] = i;
			}

			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp;
				for (int i = 0; i < 60; i++)
				{

					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout << line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{

					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
							lifeline(p, c, line, 60);
							
						}
						else
						{
							cout << endl;
							cout << "You entered " << ans;
							cout << endl;
							break;
						}
					}

				}
				for (static int k = 0; k < 10;)
				{
				
					if (n < 0)
					{
						cout << "\n-------------------------------\n";
						cout << "         Times up!!\n";
						cout << "-------------------------------\n";
						points = points - 2;
						break;
					}
					else if (ans == Sans[q])
					{
						SetConsoleTextAttribute(h, 2);
						cout << "=====================================\n";
						cout << "       Great job!Correct answer      \n";
						cout << "=====================================\n";
						SetConsoleTextAttribute(h, 7);
						cout << endl;
						k++;
						correct++;
						points = points + 10;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}

						break;
					}
					else
					{
						cout << "-------------------------------\n";
						cout << "       Wrong answer :(\n";
						cout << "-------------------------------\n";
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points - 2;
						break;
					}


				}

				if (i + 6 < 60)
				{

					cout << endl;
					cout << "Press Enter for next question:\n";
					_getch();
					cout << endl;
				}

			}

			nfile << left << setw(25) << name << setw(15) << date << setw(10) << correct << setw(13) << wrong << setw(13) << points<<endl;
			nfile.close();

		}
		if (c == 2)
		{
			char ans, Sans[10] = { 'b','a','a','d','a','b','b','b','c','c' };
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("MHistory.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i < 10; i++)
			{
				questions[i] = i;
			}
			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp;
				for (int i = 0; i < 60; i++)
				{

					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout << line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{

					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
							lifeline(p, c, line, 60);
							

						}
						else
						{
							cout << endl;
							cout << "You entered " << ans;
							cout << endl;
							break;
						}
					}

				}
				for (static int k = 0; k < 10;)
				{
					
					if (n < 0)
					{
						cout << "\n-------------------------------\n";
						cout << "         Times up!!\n";
						cout << "-------------------------------\n";
						points = points - 3;
						break;
					}
					else if (ans == Sans[q])
					{
						SetConsoleTextAttribute(h, 2);
						cout << "=====================================\n";
						cout << "       Great job!Correct answer      \n";
						cout << "=====================================\n";
						SetConsoleTextAttribute(h, 7);
						cout << endl;
						k++;
						correct++;
						points = points + 15;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}

						break;
					}
					else
					{
						cout << "-------------------------------\n";
						cout << "       Wrong answer :(\n";
						cout << "-------------------------------\n";
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points - 3;
						break;
					}


				}

				if (i + 6 < 60)
				{

					cout << endl;
					cout << "Press Enter for next question:\n";
					_getch();
					cout << endl;
				}

			}
			nfile << left << setw(25) << name << setw(15) << date << setw(10) << correct << setw(13) << wrong << setw(13) << points<<endl;
			nfile.close();
		}
		if (c == 3)
		{
			char ans, Sans[10] = { 'a','d','b','b','c','a','a','c','a','b' };
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("HHistory.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i < 10; i++)
			{
				questions[i] = i;
			}
			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp;
				for (int i = 0; i < 60; i++)
				{

					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout << line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{

					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
							lifeline(p, c, line, 60);
						
						}
						else
						{
							cout << endl;
							cout << "You entered " << ans;
							cout << endl;
							break;
						}
					}

				}
				for (static int k = 0; k < 10;)
				{
					
					if (n < 0)
					{
						cout << "\n-------------------------------\n";
						cout << "         Times up!!\n";
						cout << "-------------------------------\n";
						points = points - 5;
						break;
					}
					else if (ans == Sans[q])
					{
						cout << "-------------------------------\n";
						cout << "   Great job!Correct answer    \n";
						cout << "-------------------------------\n";
						cout << endl;
						k++;
						correct++;
						points = points + 25;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}

						break;
					}
					else
					{
						cout << "-------------------------------\n";
						cout << "       Wrong answer :(\n";
						cout << "-------------------------------\n";
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points - 5;
						break;
					}


				}

				if (i + 6 < 60)
				{

					cout << endl;
					cout << "Press Enter for next question:\n";
					_getch();
					cout << endl;
				}

			}
			nfile << left << setw(25) << name << setw(15) << date << setw(10) << correct << setw(13) << wrong << setw(13) << points<<endl;
			nfile.close();
		}
	}
	void sports(int c, string name, string date)
	{
		int points = 0, correct = 0, wrong = 0, consec = 0, number = 1;
		string line[60];
		int questions[10], temp;

		if (c == 1)
		{
			char ans, Sans[10] = { 'c','b','b','b','a','a','b','b','b','a' }, para = 's';
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("Esports.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i < 10; i++)
			{
				questions[i] = i;
			}

			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp;
				for (int i = 0; i < 60; i++)
				{

					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout << line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{

					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
							lifeline(p, c, line, 60);
						}
						else
						{
							cout << endl;
							cout << "You entered " << ans;
							cout << endl;
							break;
						}
					}

				}
				for (static int k = 0; k < 10;)
				{
					
					if (n < 0)
					{
						cout << "\n-------------------------------\n";
						cout << "         Times up!!\n";
						cout << "-------------------------------\n";
						points = points - 2;
						break;
					}
					else if (ans == Sans[q])
					{
						cout << "-------------------------------\n";
						cout << "   Great job!Correct answer    \n";
						cout << "-------------------------------\n";
						cout << endl;
						k++;
						correct++;
						points = points + 10;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}

						break;
					}
					else
					{
						cout << "-------------------------------\n";
						cout << "       Wrong answer :(\n";
						cout << "-------------------------------\n";
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points - 2;
						break;
					}


				}

				if (i + 6 < 60)
				{

					cout << endl;
					cout << "Press Enter for next question:\n";
					_getch();
					cout << endl;
				}

			}

			nfile << left << setw(25) << name << setw(15) << date << setw(10) << correct << setw(13) << wrong << setw(13) << points<<endl;
			nfile.close();

		}
		if (c == 2)
		{
			char ans, Sans[10] = { 'a','a','b','c','b','b','b','a','a','d' };
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("Msports.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i < 10; i++)
			{
				questions[i] = i;
			}
			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp;
				for (int i = 0; i < 60; i++)
				{

					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout << line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{

					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
							lifeline(p, c, line, 60);
						}
						else
						{
							cout << endl;
							cout << "You entered " << ans;
							cout << endl;
							break;
						}
					}

				}
				for (static int k = 0; k < 10;)
				{
					
					if (n < 0)
					{
						cout << "\n-------------------------------\n";
						cout << "         Times up!!\n";
						cout << "-------------------------------\n";
						points = points - 3;
						break;
					}
					else if (ans == Sans[q])
					{
						cout << "-------------------------------\n";
						cout << "   Great job!Correct answer    \n";
						cout << "-------------------------------\n";
						cout << endl;
						k++;
						correct++;
						points = points + 15;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}

						break;
					}
					else
					{
						cout << "-------------------------------\n";
						cout << "       Wrong answer :(\n";
						cout << "-------------------------------\n";
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points - 3;
						break;
					}


				}

				if (i + 6 < 60)
				{

					cout << endl;
					cout << "Press Enter for next question:\n";
					_getch();
					cout << endl;
				}

			}
			nfile << left << setw(25) << name << setw(15) << date << setw(10) << correct << setw(13) << wrong << setw(13) << points<<endl;
			nfile.close();
		}
		if (c == 3)
		{
			char ans, Sans[10] = { 'b','d','b','a','c','a','d','b','c','d' };
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("Hsports.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i < 10; i++)
			{
				questions[i] = i;
			}
			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp;
				for (int i = 0; i < 60; i++)
				{

					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout << line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{

					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
							lifeline(p, c, line, 60);
						}
						else
						{
							cout << endl;
							cout << "You entered " << ans;
							cout << endl;
							break;
						}
					}

				}
				for (static int k = 0; k < 10;)
				{
				
					if (n < 0)
					{
						cout << "\n-------------------------------\n";
						cout << "         Times up!!\n";
						cout << "-------------------------------\n";
						points = points - 5;
						break;
					}
					else if (ans == Sans[q])
					{
						cout << "-------------------------------\n";
						cout << "   Great job!Correct answer    \n";
						cout << "-------------------------------\n";
						cout << endl;
						k++;
						correct++;
						points = points + 25;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}

						break;
					}
					else
					{
						cout << "-------------------------------\n";
						cout << "       Wrong answer :(\n";
						cout << "-------------------------------\n";
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points - 5;
						break;
					}


				}

				if (i + 6 < 60)
				{

					cout << endl;
					cout << "Press Enter for next question:\n";
					_getch();
					cout << endl;
				}

			}
			nfile << left << setw(25) << name << setw(15) << date << setw(10) << correct << setw(13) << wrong << setw(13) << points<<endl;
			nfile.close();
		}
	}
	void computer(int c, string name, string date)
	{
		int points = 0, correct = 0, wrong = 0, consec = 0, number = 1;
		string line[60];
		int questions[10], temp;

		if (c == 1)
		{
			char ans, Sans[10] = { 'd','a','b','a','c','b','b','c','a','c' }, para = 's';
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("Ecomputer.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i < 10; i++)
			{
				questions[i] = i;
			}

			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp;
				for (int i = 0; i < 60; i++)
				{

					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout << line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{

					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
							lifeline(p, c, line, 60);
						}
						else
						{
							cout << endl;
							cout << "You entered " << ans;
							cout << endl;
							break;
						}
					}

				}
				for (static int k = 0; k < 10;)
				{
					
					if (n < 0)
					{
						cout << "\n-------------------------------\n";
						cout << "         Times up!!\n";
						cout << "-------------------------------\n";
						points = points - 2;
						break;
					}
					else if (ans == Sans[q])
					{
						cout << "-------------------------------\n";
						cout << "   Great job!Correct answer    \n";
						cout << "-------------------------------\n";
						cout << endl;
						k++;
						correct++;
						points = points + 10;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}

						break;
					}
					else
					{
						cout << "-------------------------------\n";
						cout << "       Wrong answer :(\n";
						cout << "-------------------------------\n";
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points - 2;
						break;
					}


				}

				if (i + 6 < 60)
				{

					cout << endl;
					cout << "Press Enter for next question:\n";
					_getch();
					cout << endl;
				}

			}

			nfile << left << setw(25) << name << setw(15) << date << setw(10) << correct << setw(13) << wrong << setw(13) << points<<endl;
			nfile.close();

		}
		if (c == 2)
		{
			char ans, Sans[10] = { 'a','b','a','a','c','a','c','a','a','a' };
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("Mcomputer.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i < 10; i++)
			{
				questions[i] = i;
			}
			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp;
				for (int i = 0; i < 60; i++)
				{

					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout << line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{

					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
						lifeline(p, c, line, 60);
							

						}
						else
						{
							cout << endl;
							cout << "You entered " << ans;
							cout << endl;
							break;
						}
					}

				}
				for (static int k = 0; k < 10;)
				{
					
					if (n < 0)
					{
						cout << "\n-------------------------------\n";
						cout << "         Times up!!\n";
						cout << "-------------------------------\n";
						points = points - 3;
						break;
					}
					else if (ans == Sans[q])
					{
						cout << "-------------------------------\n";
						cout << "   Great job!Correct answer    \n";
						cout << "-------------------------------\n";
						cout << endl;
						k++;
						correct++;
						points = points + 15;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}

						break;
					}
					else
					{
						cout << "-------------------------------\n";
						cout << "       Wrong answer :(\n";
						cout << "-------------------------------\n";
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points - 3;
						break;
					}


				}

				if (i + 6 < 60)
				{

					cout << endl;
					cout << "Press Enter for next question:\n";
					_getch();
					cout << endl;
				}

			}
			nfile << left << setw(25) << name << setw(15) << date << setw(10) << correct << setw(13) << wrong << setw(13) << points<<endl;
			nfile.close();
		}
		if (c == 3)
		{
			char ans, Sans[10] = { 'a','b','b','a','a','a','a','b','d','b' };
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("Hcomputer.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i < 10; i++)
			{
				questions[i] = i;
			}
			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp;
				for (int i = 0; i < 60; i++)
				{

					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout << line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{

					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
							lifeline(p, c, line, 60);
							
						}
						else
						{
							cout << endl;
							cout << "You entered " << ans;
							cout << endl;
							break;
						}
					}

				}
				for (static int k = 0; k < 10;)
				{
					
					if (n < 0)
					{
						cout << "\n-------------------------------\n";
						cout << "         Times up!!\n";
						cout << "-------------------------------\n";
						points = points - 5;
						break;
					}
					else if (ans == Sans[q])
					{
						cout << "-------------------------------\n";
						cout << "   Great job!Correct answer    \n";
						cout << "-------------------------------\n";
						cout << endl;
						k++;
						correct++;
						points = points + 25;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}

						break;
					}
					else
					{
						cout << "-------------------------------\n";
						cout << "       Wrong answer :(\n";
						cout << "-------------------------------\n";
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points - 5;
						break;
					}


				}

				if (i + 6 < 60)
				{

					cout << endl;
					cout << "Press Enter for next question:\n";
					_getch();
					cout << endl;
				}

			}
			nfile << left << setw(25) << name << setw(15) << date << setw(10) << correct << setw(13) << wrong << setw(13) << points<<endl;
			nfile.close();
		}
	}
	void iq(int c, string name, string date)
	{
		int points = 0, correct = 0, wrong = 0, consec = 0, number = 1;
		string line[60];
		int questions[10], temp;

		if (c == 1)
		{
			char ans, Sans[10] = { 'b','c','d','c','c','c','a','b','c','b' }, para = 's';
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("E iq.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i < 10; i++)
			{
				questions[i] = i;
			}

			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp;
				for (int i = 0; i < 60; i++)
				{

					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout << line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{

					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
							lifeline(p, c, line, 60);
							
						}
						else
						{
							cout << endl;
							cout << "You entered " << ans;
							cout << endl;
							break;
						}
					}

				}
				for (static int k = 0; k < 10;)
				{
					
					if (n < 0)
					{
						cout << "\n-------------------------------\n";
						cout << "         Times up!!\n";
						cout << "-------------------------------\n";
						points = points - 2;
						break;
					}
					else if (ans == Sans[q])
					{
						cout << "-------------------------------\n";
						cout << "   Great job!Correct answer    \n";
						cout << "-------------------------------\n";
						cout << endl;
						k++;
						correct++;
						points = points + 10;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}

						break;
					}
					else
					{
						cout << "-------------------------------\n";
						cout << "       Wrong answer :(\n";
						cout << "-------------------------------\n";
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points - 2;
						break;
					}


				}

				if (i + 6 < 60)
				{

					cout << endl;
					cout << "Press Enter for next question:\n";
					_getch();
					cout << endl;
				}

			}

			nfile << left << setw(25) << name << setw(15) << date << setw(10) << correct << setw(13) << wrong << setw(13) << points<<endl;
			nfile.close();

		}
		if (c == 2)
		{
			char ans, Sans[10] = { 'c','d','b','b','b','a','b','d','c','c' };
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("M iq.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i < 10; i++)
			{
				questions[i] = i;
			}
			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp;
				for (int i = 0; i < 60; i++)
				{

					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout << line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{

					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
							lifeline(p, c, line, 60);
							

						}
						else
						{
							cout << endl;
							cout << "You entered " << ans;
							cout << endl;
							break;
						}
					}

				}
				for (static int k = 0; k < 10;)
				{
					
					if (n < 0)
					{
						cout << "\n-------------------------------\n";
						cout << "         Times up!!\n";
						cout << "-------------------------------\n";
						points = points - 3;
						break;
					}
					else if (ans == Sans[q])
					{
						cout << "-------------------------------\n";
						cout << "   Great job!Correct answer    \n";
						cout << "-------------------------------\n";
						cout << endl;
						k++;
						correct++;
						points = points + 15;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}

						break;
					}
					else
					{
						cout << "-------------------------------\n";
						cout << "       Wrong answer :(\n";
						cout << "-------------------------------\n";
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points - 3;
						break;
					}


				}
				if (i + 6 < 60)
				{

					cout << endl;
					cout << "Press Enter for next question:\n";
					_getch();
					cout << endl;
				}

			}
			nfile << left << setw(25) << name << setw(15) << date << setw(10) << correct << setw(13) << wrong << setw(13) << points<<endl;
			nfile.close();
		}
		if (c == 3)
		{
			char ans, Sans[10] = { 'b','a','d','c','a','b','d','a','c','b' };
			ofstream nfile;
			nfile.open("score.txt", ios::app);
			if (!nfile.is_open())
			{
				cout << "Score is not opening\n";
			}
			ifstream file;
			file.open("H iq.txt", ios::in);
			if (!file.is_open())
			{
				cout << "file does not open";
			}
			srand(time(0));
			for (int i = 0; i < 10; i++)
			{
				questions[i] = i;
			}
			for (int i = 9; i >= 0; i--)
			{
				int r = rand() % (i + 1);
				temp = questions[i];
				questions[i] = questions[r];
				questions[r] = temp;
				for (int i = 0; i < 60; i++)
				{

					getline(file, line[i]);
				}
				file.close();
				int q = questions[i];
				int c = q * 6;
				char p = Sans[q];
				cout << number << ". ";
				for (int j = c; j < (c + 6); j++)
				{
					cout << line[j] << endl;
				}
				number++;
				cout << "Enter Answer (a-d) and L for lifeline:\n";
				for (n = 10; n >= 0; n--)
				{

					cout << "\rRemaining Time: " << n << " seconds ";
					Sleep(1000);
					if (_kbhit())
					{
						ans = _getch();
						if (ans == 'L' || ans == 'l')
						{
							lifeline(p, c, line, 60);
							
						}
						else
						{
							cout << endl;
							cout << "You entered " << ans;
							cout << endl;
							break;
						}
					}
				}
				for (static int k = 0; k < 10;)
				{
					
					if (n < 0)
					{
						cout << "\n-------------------------------\n";
						cout << "         Times up!!\n";
						cout << "-------------------------------\n";
						points = points - 5;
						break;
					}
					else if (ans == Sans[q])
					{
						cout << "-------------------------------\n";
						cout << "   Great job!Correct answer    \n";
						cout << "-------------------------------\n";
						cout << endl;
						k++;
						correct++;
						points = points + 25;
						consec++;
						if (consec == 3)
						{
							points = points + 5;
						}
						if (consec == 5)
						{
							points = points + 15;
							consec = 0;
						}

						break;
					}
					else
					{
						cout << "-------------------------------\n";
						cout << "       Wrong answer :(\n";
						cout << "-------------------------------\n";
						cout << "Correct answer = " << Sans[q];
						cout << endl;
						k++;
						wrong++;
						consec = 0;
						points = points - 5;
						break;
					}
				}
				if (i + 6 < 60)
				{

					cout << endl;
					cout << "Press Enter for next question:\n";
					_getch();
					cout << endl;
				}
			}
			nfile << left << setw(25) << name << setw(15) << date << setw(10) << correct << setw(13) << wrong << setw(13) << points<<endl;
			nfile.close();
		}
	}
	void lifeline(char p,int c,string x[],int size)
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		int choice;
		char ok[4] = { 'a','b','c','d' };
		string display_options[2],line[6];
		SetConsoleTextAttribute(h, 11);
		cout << "\n=====================================\n";
		SetConsoleTextAttribute(h,5);
		cout << "         ----Select lifeline----     \n";
		SetConsoleTextAttribute(h, 11);
		cout << "=====================================\n";
		SetConsoleTextAttribute(h, 7);
		cout << "\n1.remove two wrong options\n2.Extra Time\n3.Replace Question\n4.Skip Question\nchoose lifeline:";
		cin >> choice;
		if (choice == 1)
		{
			if (!skip)
			{
				srand(time(0));
				int r = rand() % 4;
				while (p == ok[r])
				{
					r = rand() % 4;
				}
				char o1 = ok[r];
				display_options[0] = x[c + (p - 'a') + 1];
				display_options[1] = x[c + (o1 - 'a') + 1];
				cout << endl;
				cout << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "Shortlist options =>" << endl;
				SetConsoleTextAttribute(h, 6);
				for (int i = 0; i < 2; i++)
				{
					cout << display_options[i] << endl;
				}
				SetConsoleTextAttribute(h, 7);
				cout << endl;
				skip = true;
			}
			else
			{
				SetConsoleTextAttribute(h,4);
				cout << "\n!!Sorry :( you have use this lifeline once !!"<<endl;
				cout << endl;
			}
		}
		if (choice == 2)
		{
			if (!extratime)
			{
				n = n + 10;
				extratime = true;
			}
			else
			{
				cout << "\n!!Sorry :( you have use this lifeline once !!" << endl;
				cout << endl;
			}
			
		}
	}