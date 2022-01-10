#include "pch.h"
#include "Memory.h"
#include <fstream>
using namespace std;

void Memory::allocate(float**& array, int row, int col) {
	array = new float* [row];
	for (int i = 0; i < row; i++)
		array[i] = new float[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			array[i][j] = 0;
}

void Memory::free(float**& array, int row, int col) {
	for (int i = 0; i < row; i++)
		delete[] array[i];
	delete array;
}
void Memory::readIris(float**& X, int row, int col) {
	ifstream file("iris.data");
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			file >> X[i][j];
			char trash;
			file >> trash;
		}
		string trashstr;
		file >> trashstr;
	}
}
void Memory::readAbalone(float**& X, int row, int col) {
	ifstream file("abalone.data");
	for (int i = 1; i <= row; i++) {
		char trash;
		file >> trash;
		for (int j = 1; j <= col; j++) {
			file >> trash;
			file >> X[i][j];
		}
	}
}
void Memory::readBalanceScale(float**& X, int row, int col)
{
	ifstream file("balance-scale.data");
	for (int i = 1; i <= row; i++)
	{
		char trash;
		file >> trash;
		for (int j = 1; j <= col; j++)
		{
			file >> trash;
			file >> X[i][j];
		}
	}
}