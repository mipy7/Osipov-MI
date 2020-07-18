/*
header.cpp

Задание 27.
*/
#include "header.h"

using namespace std;

void print(int* mas, int dim1) {
	for (int i = 0; i < dim1; ++i) {
		cout << mas[i] << ' ';
	}
	cout << endl;
}

int* bubble(int* arr, int size) {
	int temp; // временная переменная для обмена элементов местами

	// Сортировка массива пузырьком
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				// меняем элементы местами
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr;
}

void decode(int* mas, int* masTask, int*& narr, int dim, int dim2) {
	for (int i = 0; i < dim2; ++i)
		narr[i] = 0;

	for (int i = 0; i < dim; ++i)
		narr[mas[i]] += masTask[i];
}

void copy(int* from, int* to, int dim) {
	for (int i = 0; i < dim; ++i)
		to[i] = from[i];
}

bool equal(int* mas1, int* mas2, int size) {
	bool flag = 1;
	int i = 0;
	while (flag && i < size) {
		flag = mas1[i] == mas2[i];
		++i;
	}
	return flag;
}

int* Task27(int* Task, int* Mash, int* fragmentation, int TaskSize, int MashSize) {
	/* Вычисление */

	// сортировка массива задач
	Task = bubble(Task, TaskSize);

	// инициализация массива для хранения лучшего результата в виде задач
	int* best = new int[TaskSize];
	for (int i = 0; i < TaskSize; ++i)
		best[i] = 0;

	// инициализация массива для хранения лучшего результата в виде машины с задачами
	int* bestM = new int[MashSize];

	// флаг для выхода из цикла
	int flag = 1;

	// основная программа
	while (flag) {
		/* Счетчик (переход на следующий разряд)*/
		if (fragmentation[0] == MashSize)
			for (int i = 0; i < TaskSize; ++i) {

				if (fragmentation[TaskSize - 1] == MashSize) {
					fragmentation[TaskSize - 1]--;
					flag = 0;
				}
				else if (fragmentation[i] == MashSize) {
					fragmentation[i] = 0;
					fragmentation[i + 1] += 1;
				}
			}

		/* Сохранение максимума */
		int k = 0; // переменная-счетчик для сравнения массивов в цикле while
		int flag1 = 1; // флаг для выхода из массива сравнения
		decode(fragmentation, Task, Mash, TaskSize, MashSize); // расшифровываем и разносим задачи по машинам
		decode(best, Task, bestM, TaskSize, MashSize); // расшифровываем и разносим задачи по машинам (ниже сравним с предыдущим)
		Mash = bubble(Mash, MashSize); // сортировка машин по убыванию задач
		bestM = bubble(bestM, MashSize); // сортировка машин по убыванию задач
		while (flag1) { // цикл проверки наилучшей перестановки   (( можно переделать как функцию с рекурсией ))
			if (k == MashSize) flag1 = 0; // если дошли до конца массива то выходим из цикла
			if (bestM[k] < Mash[k]) flag1 = 0; // если максимум в наилучшем результате по машинам ниже чем в текущем массиве машин то выходим из цикла
			if (bestM[k] > Mash[k]) { // если максимум в наилучшем результате больше чем по текущим машинам то:
				copy(fragmentation, best, TaskSize); // 1) копируем лучший результат
				flag1 = 0; // 2) выходим из цикла
			}
			k++; // если не вышли из цикла продолжаем сравнивать массивы
		}

		/* Счетчик */
		++fragmentation[0];
	}

	return best;
}

void printdecode(int* Code, int* Task, int*& Mash, int SizeTask, int SizeMash) {
	decode(Code, Task, Mash, SizeTask, SizeMash);
	for (int i = 0; i < SizeMash; ++i) {
		cout << "Машина " << i+1 << ": " << Mash[i] << " | ";
		for (int j = 0; j < SizeTask; ++j) {
			if (Code[j] == i) cout << Task[j] << ", ";
		}
		cout << endl;
	}
}
