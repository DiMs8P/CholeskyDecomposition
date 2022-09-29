#include "MatrixFileReader.h"

MatrixFileReader::MatrixFileReader(const string& path)
	: FileReader(path)
	{ }

void MatrixFileReader::Read(vector<vector<real>>& matrix)
{
	ifstream stream = getStream();

	stream >> _width;
	stream >> _height;

	matrix.resize(_width);
	for (int i = 0; i < _width; i++)
		matrix[i].resize(_height);

	for (int i = 0; i < _width; ++i)
		for (int j = 0; j < _height; ++j)
			stream >> matrix[i][j];

	stream.close();
}