/*
header.h

Задание 27.
*/
#pragma once

#include <iostream>

using namespace std;

// функция печати одномерного массива
void print(int* mas, int dim1);

// сортировка(убывание)
int* bubble(int* arr, int size);

// перевод задач на массив машин
void decode(int* mas, int* masTask, int*& narr, int dim, int dim2);

// копирование массивов
void copy(int* from, int* to, int dim);

// сравнение массивов(предполагаем что размерности массивов одинаоквые)
bool equal(int* mas1, int* mas2, int size);

// основная задача
int* Task27(int* Task, int* Mash, int* fragmentation, int TaskSize, int MashSize);

void printdecode(int* Code, int* Task, int*& Mash, int SizeTask, int SizeMash);
