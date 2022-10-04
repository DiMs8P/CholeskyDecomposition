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
	ofstream stream(_outputPath);

	const int height = matrix.size();
	const int width = matrix[0].size();

	stream << height << " " << width << '\n';
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			stream << fixed << setprecision(PRECISION) << matrix[i][j] << '\t';
		}
		stream << '\n';
	}

	stream.close();
}
