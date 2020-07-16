/*
main.cpp

������� 27.
����������� ���������� ��� ���������� �����
�������� ���������, ������� ��� ��������� ��������� ����� (��� ������ ������ ������� ����� � ���������� pi)
������ ����������� ���������� ���������� ���� ������ �� �������� (m) ���������� ���������� �� �������� ������ �����.
���������� ���������� ����� �� ������� �������� � ���� ��� ������ ������ ������ �����, ������� �� ��� ����� �����������.
����������� ��������� ����������, ��� ������� ������������ ����� ������������� ���� ����� ����������.
*/

#include <ctime>
#include "header.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	/* ����� */

	{ // ���� 1
		int TaskSize = 7;
		int MashSize = 3;

		int* Task = new int[TaskSize] { 34, 8, 25, 9, 14, 30, 6 };
		int* Mash = new int[MashSize] { 0, 0, 0 };
		int* fragmentation = new int[TaskSize] { 0, 0, 0, 0, 0, 0, 0 };

		cout << "���� 1" << endl;
		cout << "������� ������:" << endl;
		cout << "������:" << endl;
		print(Task, TaskSize);
		cout << "������:" << endl;
		print(Mash, MashSize);
		cout << "==================\n\n";


		// ������ ������� �������
		clock_t start = clock();

		int* best = Task27(Task, Mash, fragmentation, TaskSize, MashSize);

		// ����� ������� �������
		clock_t stop = clock();

		// ���������� ������
		int seconds = stop - start;


		decode(best, Task, Mash, TaskSize, MashSize);
		Mash = bubble(Mash, MashSize);
		int* TestMash = new int[MashSize] { 44, 42, 40 };

		cout << "��������� ������� ��������:" << endl;
		cout << "������:" << endl;
		print(Mash, MashSize);

		cout << "\n���������� �����:" << endl;
		print(TestMash, MashSize);
		cout << "==================\n\n";



		if (equal(TestMash, Mash, MashSize)) cout << "���� 1: ������� " ;
		else cout << "���� 1: �� ������� ";

		cout << "(����� ������ ���������: " << seconds << ") " << endl;

		cout << endl;
	}

	{ // ���� 2
		int TaskSize = 12;
		int MashSize = 4;

		int* Task = new int[TaskSize] { 6, 3, 15, 7, 23, 30, 21, 4, 5, 32, 26, 13 };
		int* Mash = new int[MashSize] { 0, 0, 0, 0 };
		int* fragmentation = new int[TaskSize] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  };

		cout << "���� 2" << endl;
		cout << "������� ������:" << endl;
		cout << "������:" << endl;
		print(Task, TaskSize);
		cout << "������:" << endl;
		print(Mash, MashSize);
		cout << "==================\n\n";

		// ������ ������� �������
		clock_t start = clock();

		int* best = Task27(Task, Mash, fragmentation, TaskSize, MashSize);

		// ����� ������� �������
		clock_t stop = clock();

		// ���������� ������
		int seconds = stop - start;

		decode(best, Task, Mash, TaskSize, MashSize);
		Mash = bubble(Mash, MashSize);
		int* TestMash = new int[MashSize] { 47, 47, 46, 45 };


		cout << "��������� ������� ��������:" << endl;
		cout << "������:" << endl;
		print(Mash, MashSize);

		cout << "\n���������� �����:" << endl;
		print(TestMash, MashSize);
		cout << "==================\n\n";


		if (equal(TestMash, Mash, MashSize)) cout << "���� 2: �������";
		else cout << "���� 2: �� �������";

		cout << "(����� ������ ���������: " << seconds << ") " << endl;

		cout << endl;
	}

	{ // ���� 3
		int TaskSize = 3;
		int MashSize = 6;

		int* Task = new int[TaskSize] { 5, 20, 15};
		int* Mash = new int[MashSize] { 0, 0, 0, 0, 0, 0 };
		int* fragmentation = new int[TaskSize] { 0, 0, 0  };

		cout << "���� 3" << endl;
		cout << "������� ������:" << endl;
		cout << "������:" << endl;
		print(Task, TaskSize);
		cout << "������:" << endl;
		print(Mash, MashSize);
		cout << "==================\n\n";

		// ������ ������� �������
		clock_t start = clock();

		int* best = Task27(Task, Mash, fragmentation, TaskSize, MashSize);

		// ����� ������� �������
		clock_t stop = clock();

		// ���������� ������
		int seconds = stop - start;

		decode(best, Task, Mash, TaskSize, MashSize);
		Mash = bubble(Mash, MashSize);
		int* TestMash = new int[MashSize] { 20, 15, 5, 0, 0, 0 };


		cout << "��������� ������� ��������:" << endl;
		cout << "������:" << endl;
		print(Mash, MashSize);

		cout << "\n���������� �����:" << endl;
		print(TestMash, MashSize);
		cout << "==================\n\n";


		if (equal(TestMash, Mash, MashSize)) cout << "���� 3: �������";
		else cout << "���� 3: �� �������";

		cout << "(����� ������ ���������: " << seconds << ") " << endl;
	
		cout << endl;
	}


	/* ������������� */

	int TaskSize = 0; // ���������� �����
	int MashSize = 0; // ���������� �����

	int* Task; // ������ �����
	int* Mash; // ������ ����� 

	int* fragmentation; // ������ �������������( ����������� TaskSize )

	cout << "������� ���������� �����: " << endl;
	cin >> TaskSize;
	cout << "������� ���������� �����: " << endl;
	cin >> MashSize;

	Task = new int[TaskSize];
	Mash = new int[MashSize];

	fragmentation = new int[TaskSize];

	for (int i = 0; i < TaskSize; ++i) {
		cout << "������ " << i + 1 << ": ";
		cin >> Task[i];
	}

	for (int i = 0; i < TaskSize; ++i)
		fragmentation[i] = 0;

	for (int i = 0; i < MashSize; ++i)
		Mash[i] = 0;

	/* ��������� */
	// ������ ������� �������
	clock_t start = clock();

	int* best = Task27(Task, Mash, fragmentation, TaskSize, MashSize);

	// ����� ������� �������
	clock_t stop = clock();

	// ���������� ������
	int seconds = stop - start;


	/* ����� ���������� �� ����� */

	cout << endl;
	printdecode(best, Task, Mash, TaskSize, MashSize);
	cout << "(����� ������ ���������: " << seconds << ") " << endl;
	cout << endl;

	system("pause");

	return 0;
}