#include <fstream>
#include "Reader.h"

void FileReader::ReadMatrix(vector<vector<real>>& Matrix, const string& Path) {
	ifstream triangleStream(Path);
	if (!triangleStream.is_open())
	{
		throw "File is empty!";
	}

	int matrixSize;
	int tapeHalfSize;
	triangleStream >> tapeHalfSize;
	triangleStream >> matrixSize;

	Matrix.resize(matrixSize);
	for (int i = 0; i < matrixSize; i++) {
		Matrix[i].resize(tapeHalfSize);
	}

	for (int i = 0; i < matrixSize; ++i)
		for (int j = 0; j < tapeHalfSize; ++j)
			triangleStream >> Matrix[i][j];

	triangleStream.close();
}

void FileReader::ReadVector(vector<real>& Vector, const string& Path) {
	ifstream vectorStream(Path);
	if (!vectorStream.is_open())
	{
		throw "File is empty!";
	}

	int VectorSize;
	vectorStream >> VectorSize;
	Vector.resize(VectorSize);

	for (int i = 0; i < VectorSize; ++i)
	{
		vectorStream >> Vector[i];
	}

	vectorStream.close();
}