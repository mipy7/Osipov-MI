/*
header.h

������� 27.
*/
#pragma once

#include <iostream>

using namespace std;

// ������� ������ ����������� �������
void print(int* mas, int dim1);

// ����������(��������)
int* bubble(int* arr, int size);

// ������� ����� �� ������ �����
void decode(int* mas, int* masTask, int*& narr, int dim, int dim2);

// ����������� ��������
void copy(int* from, int* to, int dim);

// ��������� ��������(������������ ��� ����������� �������� ����������)
bool equal(int* mas1, int* mas2, int size);

// �������� ������
int* Task27(int* Task, int* Mash, int* fragmentation, int TaskSize, int MashSize);

void printdecode(int* Code, int* Task, int*& Mash, int SizeTask, int SizeMash);