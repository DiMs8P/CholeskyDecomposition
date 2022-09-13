#include "Writer.h"

void Writer::WriteVectorToFile(std::vector<real>& Vector, const std::string& Path) {
	std::ofstream vectorStream(Path);

	for (int i = 0; i < Vector.size(); i++) {
		vectorStream << std::fixed << std::setprecision(PRECISION) << Vector[i] << '\n';
	}

	vectorStream.close();
}

void Writer::WriteMatrixToFile(const std::vector<std::vector<real>>& Matrix, const std::string& Path) {
	std::ofstream MatrixStream(Path);

	const int MatrixSize = Matrix.size();
	const int HalfSize = Matrix[0].size();

	for (int i = 0; i < MatrixSize; i++) {
		for (int j = 0; j < HalfSize; j++) {
			MatrixStream << std::fixed << std::setprecision(PRECISION) << Matrix[i][j] << '\t';
		}
		MatrixStream << '\n';
	}

	MatrixStream.close();
}