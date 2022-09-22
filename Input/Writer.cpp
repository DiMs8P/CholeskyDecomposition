#include <fstream>
#include <iomanip>
#include "Writer.h"


void FileWriter::WriteVector(std::vector<real>& Vector, const std::string& Path) {
	std::ofstream vectorStream(Path);

	vectorStream << Vector.size() << '\n';
	for (int i = 0; i < Vector.size(); i++) {
		vectorStream << std::fixed << std::setprecision(PRECISION) << Vector[i] << '\n';
	}

	vectorStream.close();
}

void FileWriter::WriteMatrix(const std::vector<std::vector<real>>& Matrix, const std::string& Path) {
	std::ofstream MatrixStream(Path);

	const int MatrixSize = Matrix.size();
	const int HalfSize = Matrix[0].size();

	MatrixStream << MatrixSize << " " << HalfSize << '\n';
	for (int i = 0; i < MatrixSize; i++) {
		for (int j = 0; j < HalfSize; j++) {
			MatrixStream << std::fixed << std::setprecision(PRECISION) << Matrix[i][j] << '\t';
		}
		MatrixStream << '\n';
	}

	MatrixStream.close();
}