#pragma once
class Memory
{
public:
	void allocate(float**& array, int row, int col);
	void free(float**& array, int row, int col);
	void readIris(float**& X, int row, int col);
	void readAbalone(float**& X, int row, int col);
	void readBalanceScale(float**& X, int row, int col);

};
