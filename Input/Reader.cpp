#include <fstream>
#include "Reader.h"

void FileReader::ReadMatrix(vector<vector<real>>& matrix, const string& path) {
	ifstream triangleStream(path);
	if (!triangleStream.is_open())
	{
		throw "File is empty!";
	}

	int matrixSize;
	int tapeHalfSize;
	triangleStream >> tapeHalfSize;
	triangleStream >> matrixSize;

	matrix.resize(matrixSize);
	for (int i = 0; i < matrixSize; i++) {
		matrix[i].resize(tapeHalfSize);
	}

	for (int i = 0; i < matrixSize; ++i)
		for (int j = 0; j < tapeHalfSize; ++j)
			triangleStream >> matrix[i][j];

	triangleStream.close();
}

void FileReader::ReadVector(vector<real>& Vector, const string& path) {
	ifstream vectorStream(path);
	if (!vectorStream.is_open())
	{
		throw "File is empty!";
	}

	int vectorSize;
	vectorStream >> vectorSize;
	Vector.resize(vectorSize);

	for (int i = 0; i < vectorSize; ++i)
	{
		vectorStream >> Vector[i];
	}

	vectorStream.close();
}