#include <fstream>
#include <iomanip>
#include "Writer.h"

FileWriter::FileWriter(const string& outputPath) :
	_outputPath(outputPath)
{ }

void FileWriter::WriteVector(const vector<real>& vector) const
{
	ofstream vectorStream(_outputPath);

	vectorStream << vector.size() << '\n';
	for (const float x : vector)
		vectorStream << fixed << setprecision(PRECISION) << x << '\n';

	vectorStream.close();
}

void FileWriter::WriteMatrix(const vector<vector<real>>& matrix) const
{
	ofstream matrixStream(_outputPath);

	const int matrixSize = matrix.size();
	const int halfSize = matrix[0].size();

	matrixStream << matrixSize << " " << halfSize << '\n';
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < halfSize; j++) {
			matrixStream << fixed << setprecision(PRECISION) << matrix[i][j] << '\t';
		}
		matrixStream << '\n';
	}

	matrixStream.close();
}
