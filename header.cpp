/*
header.cpp

������� 27.
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
	int temp; // ��������� ���������� ��� ������ ��������� �������

	// ���������� ������� ���������
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				// ������ �������� �������
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
	/* ���������� */

	// ���������� ������� �����
	Task = bubble(Task, TaskSize);

	// ������������� ������� ��� �������� ������� ���������� � ���� �����
	int* best = new int[TaskSize];
	for (int i = 0; i < TaskSize; ++i)
		best[i] = 0;

	// ������������� ������� ��� �������� ������� ���������� � ���� ������ � ��������
	int* bestM = new int[MashSize];

	// ���� ��� ������ �� �����
	int flag = 1;

	// �������� ���������
	while (flag) {
		/* ������� (������� �� ��������� ������)*/
		if (fragmentation[0] == MashSize)
			for (int i = 0; i < TaskSize; ++i) {

				if (fragmentation[TaskSize - 1] == MashSize)
					flag = 0;
				else if (fragmentation[i] == MashSize) {
					fragmentation[i] = 0;
					fragmentation[i + 1] += 1;
				}
			}

		/* ���������� ��������� */
		int k = 0; // ����������-������� ��� ��������� �������� � ����� while
		int flag1 = 1; // ���� ��� ������ �� ������� ���������
		decode(fragmentation, Task, Mash, TaskSize, MashSize); // �������������� � �������� ������ �� �������
		decode(best, Task, bestM, TaskSize, MashSize); // �������������� � �������� ������ �� ������� (���� ������� � ����������)
		Mash = bubble(Mash, MashSize); // ���������� ����� �� �������� �����
		bestM = bubble(bestM, MashSize); // ���������� ����� �� �������� �����
		while (flag1) { // ���� �������� ��������� ������������   (( ����� ���������� ��� ������� � ��������� ))
			if (k == MashSize) flag1 = 0; // ���� ����� �� ����� ������� �� ������� �� �����
			if (bestM[k] < Mash[k]) flag1 = 0; // ���� �������� � ��������� ���������� �� ������� ���� ��� � ������� ������� ����� �� ������� �� �����
			if (bestM[k] > Mash[k]) { // ���� �������� � ��������� ���������� ������ ��� �� ������� ������� ��:
				copy(fragmentation, best, TaskSize); // 1) �������� ������ ���������
				flag1 = 0; // 2) ������� �� �����
			}
			k++; // ���� �� ����� �� ����� ���������� ���������� �������
		}

		/* ������� */
		++fragmentation[0];
	}

	return best;
}

void printdecode(int* Code, int* Task, int*& Mash, int SizeTask, int SizeMash) {
	decode(Code, Task, Mash, SizeTask, SizeMash);
	for (int i = 0; i < SizeMash; ++i) {
		cout << "������ " << i+1 << ": " << Mash[i] << " | ";
		for (int j = 0; j < SizeTask; ++j) {
			if (Code[j] == i) cout << Task[j] << ", ";
		}
		cout << endl;
	}
}