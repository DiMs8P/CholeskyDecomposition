#include "SolverOfSLAE.h"

std::vector<real> SolverOfSLAE::SolveWithLowerTriangle(
	const std::vector<std::vector<real>>& Matrix,
	const std::vector<real>& Diag,
	const std::vector<real>& Vector)
{
	std::vector<real> Output(Vector.size());
	const int HalfSize = Matrix[0].size();
	real Accumulator = 0;

	for (int i = 0; i < HalfSize; i++) {

		for (int j = 0; j < i; j++) {
			Accumulator += Matrix[i][HalfSize - i + j] * Output[j];
		}
		Output[i] = (Vector[i] - Accumulator) / Diag[i];
		Accumulator = 0;
	}


	for (int i = HalfSize; i < Matrix.size(); i++) {

		for (int j = 0; j < HalfSize; j++) {
			Accumulator += Matrix[i][j] * Output[j + i - HalfSize];
		}
		Output[i] = (Vector[i] - Accumulator) / Diag[i];
		Accumulator = 0;
	}

	return Output;
}

std::vector<real> SolverOfSLAE::SolveWithHigherTriangle(const std::vector<std::vector<real>>& Matrix,
	const std::vector<real>& Diag,
	const std::vector<real>& Vector)
{
	std::vector<real> Output(Vector.size());
	const int HalfSize = Matrix[0].size();
	const int MatrixSize = Matrix.size();
	real Accumulator = 0;

	Output[MatrixSize - 1] = Vector[MatrixSize - 1] / Diag[MatrixSize - 1];

	for (int i = MatrixSize - 1; i >= MatrixSize - HalfSize; i--) {

		for (int k = 0; k < MatrixSize - i; k++) {
			Accumulator += Matrix[i + k][HalfSize - k - 1] * Output[i + k];
		}
		Output[i - 1] = (Vector[i - 1] - Accumulator) / Diag[i - 1];
		Accumulator = 0;
	}


	for (int i = MatrixSize - HalfSize; i > 0; i--) {

		for (int k = 0; k < HalfSize; k++) {
			Accumulator += Matrix[i + k][HalfSize - 1 - k] * Output[i + k];
		}
		Output[i - 1] = (Vector[i - 1] - Accumulator) / Diag[i - 1];
		Accumulator = 0;
	}

	return Output;

}