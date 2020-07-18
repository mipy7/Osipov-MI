/*
main.cpp

Задание 27.
Оптимальное расписание для идентичных машин
Написать программу, которая для заданного множества задач (для каждой задачи указано время её выполнения pi)
строит оптимальное расписание выполнения этих задача на заданном (m) количестве идентичных по скорости работы машин.
Расписание выполнения задач на машинах включает в себя для каждой машины список задач, которые на ней будут выполняться.
Оптимальным считается расписание, при котором максимальное время загруженности всех машин минимально.
*/

#include <chrono>
#include "header.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	/* Тесты */
	{ // Тест 1
		int TaskSize = 1;
		int MashSize = 3;

		int* Task = new int[TaskSize] { 34 };
		int* Mash = new int[MashSize] { 0, 0, 0 };
		int* fragmentation = new int[TaskSize] { 0 };

		cout << "Тест 1" << endl;
		cout << "Входные данные:" << endl;
		cout << "Задачи: ";
		print(Task, TaskSize);
		cout << "Кол-во машин:" << MashSize << endl;
	

		// начало отсчета времени
		auto startTime = chrono::high_resolution_clock::now();

		int* best = Task27(Task, Mash, fragmentation, TaskSize, MashSize);

		// конец отсчета времени
		auto finishTime = chrono::high_resolution_clock::now();

		// количество секунд
		auto seconds = chrono::duration_cast<chrono::microseconds>(finishTime - startTime);

		int* TestMash = new int[MashSize] { 34, 0, 0 };

		cout << "Программа вернула значения:" << endl;
		printdecode(best, Task, Mash,TaskSize, MashSize);
		Mash = bubble(Mash, MashSize);


		if (equal(TestMash, Mash, MashSize)) cout << "Тест 1: пройден " << endl;
		else cout << "Тест 1: Не пройден " << endl;
		cout << "==================\n\n";
	}

	{ // Тест 2
		int TaskSize = 3;
		int MashSize = 3;

		int* Task = new int[TaskSize] { 6, 3, 7};
		int* Mash = new int[MashSize] { 0, 0, 0 };
		int* fragmentation = new int[TaskSize] { 0, 0, 0};

		cout << "Тест 2" << endl;
		cout << "Входные данные:" << endl;
		cout << "Задачи: ";
		print(Task, TaskSize);
		cout << "Кол-во машин:" << MashSize << endl;

		// начало отсчета времени
		auto startTime = chrono::high_resolution_clock::now();

		int* best = Task27(Task, Mash, fragmentation, TaskSize, MashSize);

		// конец отсчета времени
		auto finishTime = chrono::high_resolution_clock::now();

		// количество секунд
		auto seconds = chrono::duration_cast<chrono::microseconds>(finishTime - startTime);


		int* TestMash = new int[MashSize] { 7, 6, 3 };

		cout << "Программа вернула значения:" << endl;
		printdecode(best, Task, Mash, TaskSize, MashSize);

		Mash = bubble(Mash, MashSize);

		if (equal(TestMash, Mash, MashSize)) cout << "Тест 2: пройден" << endl;
		else cout << "Тест 2: Не пройден" << endl;
		cout << "==================\n\n";
	}

	{ // Тест 3
		int TaskSize = 5;
		int MashSize = 3;

		int* Task = new int[TaskSize] { 5, 20, 15, 7, 12};
		int* Mash = new int[MashSize] { 0, 0, 0 };
		int* fragmentation = new int[TaskSize] { 0, 0, 0, 0, 0 };

		cout << "Тест 3" << endl;
		cout << "Входные данные:" << endl;
		cout << "Задачи: ";
		print(Task, TaskSize);
		cout << "Кол-во машин:" << MashSize << endl;


		// начало отсчета времени
		auto startTime = chrono::high_resolution_clock::now();

		int* best = Task27(Task, Mash, fragmentation, TaskSize, MashSize);

		// конец отсчета времени
		auto finishTime = chrono::high_resolution_clock::now();

		// количество секунд
		auto seconds = chrono::duration_cast<chrono::microseconds>(finishTime - startTime);

		int* TestMash = new int[MashSize] { 20, 20, 19};


		cout << "Программа вернула значения:" << endl;
		printdecode(best, Task, Mash, TaskSize, MashSize);

		Mash = bubble(Mash, MashSize);

		if (equal(TestMash, Mash, MashSize)) cout << "Тест 3: пройден" << endl;
		else cout << "Тест 3: Не пройден" << endl;
		cout << "==================\n\n";
	}


	/* Инициализация */

	int TaskSize = 0; // количество задач
	int MashSize = 0; // количество машин

	int* Task; // массив задач
	int* Mash; // массив машин 

	int* fragmentation; // массив распределения( размерность TaskSize )

	cout << "Введите количество задач: " << endl;
	cin >> TaskSize;
	cout << "Введите количество машин: " << endl;
	cin >> MashSize;

	Task = new int[TaskSize];
	Mash = new int[MashSize];

	fragmentation = new int[TaskSize];

	for (int i = 0; i < TaskSize; ++i) {
		cout << "Задача " << i + 1 << ": ";
		cin >> Task[i];
	}

	for (int i = 0; i < TaskSize; ++i)
		fragmentation[i] = 0;

	for (int i = 0; i < MashSize; ++i)
		Mash[i] = 0;

	/* Программа */
		// начало отсчета времени
	auto startTime = chrono::high_resolution_clock::now();

	int* best = Task27(Task, Mash, fragmentation, TaskSize, MashSize);

	// конец отсчета времени
	auto finishTime = chrono::high_resolution_clock::now();

	// количество секунд
	auto seconds = chrono::duration_cast<chrono::microseconds>(finishTime - startTime);


	/* Вывод результата на экран */

	cout << endl;
	printdecode(best, Task, Mash, TaskSize, MashSize);
	cout << "(Время работы программы: " << seconds.count() << ") " << endl;
	cout << endl;

	system("pause");

	return 0;
}
