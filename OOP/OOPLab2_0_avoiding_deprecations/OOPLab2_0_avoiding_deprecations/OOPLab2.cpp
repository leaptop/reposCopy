#include <string>
#include <iostream>
#include <fstream>
#include<vector>
#include <limits>
#include <cstdio>
/*
������������ ������ �2
����: ���������� � �������� � C++
1. ����������� ����� ����, ������� ����������� ����� ������������ � ���������
��������������� ��������.
2. ����� ���� �������� ����������� ��� ������� ���������� ���������, ������� ���������
������� ����� � ��������� �� � ����� �����.
3. �������� ������ ���� ���������� � ���� ������, �������� ��������� ������:
�����		��������
�������
���� �������� ����� ��� ��������� �� �����
������
������
������������ ������ ������, ������� ����������� �
�������� ������
��������
�����
���������� ���� �����, ������� ������ ��������


����� ����� ����� ����� �� ���� ������
��������
�����
�������� ���� ������� ������� ����� �� ������
��������
��������
������� �����, �������� ����������
���������
����
��������� ��������� � �������� ����� ���� ��� �������
����� ���� � �������� ������
4. � ������ ������������� ������������ ����� string:
#include <string>
*/
using std::string;//or you can write "using namespace std;"
using std::cout;
using std::cin;
using std::endl;
//using std::vector;

using namespace std;

class terminal {

public:
	FILE * f;
	string path;
	int x = 1000;

	//terminal():x(100), buffer(x) {	}// ��� ���������������� ����� �����?
	void openFile() {//�������� ����� ��� ��������� �� �����


	   // FILE *pFile;
		//char buffer[1000];

		//fopen_s(&f,"myfile.txt", "r");
		//if (f == NULL) perror("\nError opening file");
		//else
		//{
		   // cout << "\nopening";
		   // /*while (!feof(pFile))
		   // {
		   //	 if (fgets(buffer, 100, pFile) == NULL) break;
		   //	 fputs(buffer, stdout);
		   // }*/
		   //
		//}
	   //cout << "������� ��� ����� ��� ��������\n";
	   //cin >> buffer;
	   //fopen_s(&f, buffer, "rb");
	   //if (f==NULL) {
	   //	cout << "������ �������� �����(��� ��� �������� ���������)" << endl;
	   //}
	   //else {
	   //	cout << "���� ������" << endl;
	   //	/*char ch;
	   //	while (fin.get(ch)) {
	   //	cout << ch;
	   //	}*/
	   //}
	   // system("PAUSE");
	   // fclose(f);
	}
	void insertAString() {//������������ ������ ������, ������� ����������� � �������� ������
						  //��� �� ������ ������ ����� ��������� � ��������... ����� ��������� ������ ���� ����...
		//fout.open(path, std::ios::app);//app - append
		fopen_s(&f, "myfile.txt", "a");
		cout << "\n ������� �����:\n" << endl;
		char str[256];
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		fgets(str, 255, stdin);
		//fputs( str, f);
		fprintf(f, "\n");
		for (int i = 0; i < 255, str[i] != '\n'; i++)
		{
			fprintf(f, "%c", str[i]);
		}

		//fprintf(f, "\n");
		fclose(f);
		//getchar();
	}


	void showText() {//���������� ���� �����, ������� ������ ��������
		system("CLS");
		char buffer[1000];
		fopen_s(&f, "myfile.txt", "r+");

		if (f == NULL) perror("Error opening file");
		else
		{
			while (!feof(f))
			{
				if (fgets(buffer, x, f) == NULL) break;
				fputs(buffer, stdout);
			}
			cout << "\n";
			fclose(f);
			system("PAUSE"); system("CLS");
		}
		//for (int i = 0; i < x, fgets(buffer, 5, f) != NULL; i++)
		//{
		//	//while (fgets(buffer, 5, f) != NULL)//�������� ����� �� ������ ��������� ������ ������
		//	cout << buffer[i];
		//}
	}


	void wordSearch() {//����� ����� �� ���� ������
		ifstream input;
		size_t pos;
		string line;
		char str[30];
		int sn = 0;
		int se = 0;

		input.open("myfile.txt");
		//fopen_s(&input, "myfile.txt", "r");
		if (input.is_open())
		{
			while (getline(input, line))
			{
				se--;
				sn++;
				pos = line.find("A");
				if (pos != string::npos) // string::npos is returned if string is not found
				{
					cout << "Found at line �" << sn;
					break;
				}

			}
		//else cout << "Couldn't find";
		}

		system("pause");
		system("CLS");
	}
	void deleteAWord() {//�������� ���� ������� ������� ����� �� ������

	}
	void clearTerminal() {//������� �����, �������� ����������

	}
	void saveFile() {//��������� ��������� � �������� ����� ���� ��� ������� ����� ���� � �������� ������

	}

};
class menu : public terminal {
	//terminal::openFile();
public: void showMenu() {
	//system("CLS");
	int num = 0;
	cout << "\n������� �������:\n 0 ������� ����\n 1 ������ ������ � ����\n 2 �������� ����� �����\n 3 ����� �����\n";
	//system("PAUSE");
	//fflush(stdin);
	//_flushall();
	//cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	scanf_s("%d", &num);
	//system("CLS");
	switch (num) {
	case 0: {openFile();   break; }
	case 1: {insertAString();  break; }
	case 2: {showText();  break; }
	case 3: {wordSearch(); break; }
	default: system("CLS");
		//system("PAUSE");

	}
}
};

int main() {
	setlocale(LC_ALL, "ru");
	menu a;
	//system("PAUSE");
	while (true) {

		a.showMenu();

	}
	getchar();
	std::vector <int> v1(3);
	vector<int> myVector;
	return 0;
}

/*
������������ ������ �2
����: ���������� � �������� � C++
1. ����������� ����� ����, ������� ����������� ����� ������������ � ���������
��������������� ��������.
2. ����� ���� �������� ����������� ��� ������� ���������� ���������, ������� ���������
������� ����� � ��������� �� � ����� �����.
3. �������� ������ ���� ���������� � ���� ������, �������� ��������� ������:
�����		��������
�������
���� �������� ����� ��� ��������� �� �����
������
������
������������ ������ ������, ������� ����������� �
�������� ������
��������
�����
���������� ���� �����, ������� ������ ��������
����� ����� ����� ����� �� ���� ������
��������
�����
�������� ���� ������� ������� ����� �� ������
��������
��������
������� �����, �������� ����������
���������
����
��������� ��������� � �������� ����� ���� ��� �������
����� ���� � �������� ������
4. � ������ ������������� ������������ ����� string:
#include <string>
*/
class terminal_00 {

public:
	string path;
	ifstream fin;
	ofstream fout;
public: void openFile() {//�������� ����� ��� ��������� �� �����


	cout << "������� ��� ����� ��� ��������\n";
	cin >> path;
	fin.open(path, std::ios::out);
	if (!fin.is_open()) {
		cout << "������ �������� �����(��� ��� �������� ���������)" << endl;
	}
	else {
		cout << "���� ������" << endl;
		/*char ch;
		while (fin.get(ch)) {
		cout << ch;
		}*/
	}
	fin.close();
	getchar();
}
		void insertAString() {//������������ ������ ������, ������� ����������� � �������� ������
							  //��� �� ������ ������ ����� ��������� � ��������... ����� ��������� ������ ���� ����...
			fout.open(path, std::ios::app);//app - append
			cout << "\n ������� �����:\n" << endl;
			string str;
			cin >> str;
			fout << str;
			fout.close();
			getchar();
		}


		void showText() {//���������� ���� �����, ������� ������ ��������
			fin.open(path, std::ios::out);
			char ch;
			while (fin.get(ch)) {
				cout << ch;
			}

			fin.close();
			getchar();
		}


		void wordSearch() {//����� ����� �� ���� ������

		}
		void deleteAWord() {//�������� ���� ������� ������� ����� �� ������

		}
		void clearTerminal() {//������� �����, �������� ����������

		}
		void saveFile() {//��������� ��������� � �������� ����� ���� ��� ������� ����� ���� � �������� ������

		}

};