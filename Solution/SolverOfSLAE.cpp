#include "SolverOfSLAE.h"

std::vector<real> SolverOfSLAE::SolveWithLowerTriangle(
	const std::vector<std::vector<real>>& Matrix,
	const std::vector<real>& Diag,
	const std::vector<real>& Vector)
{
	if (Matrix.empty())
		return {};

	std::vector<real> Output(Vector.size());
	const int HalfSize = Matrix[0].size();

	for (int i = 0; i < HalfSize; i++) {

		accVarType Sum = 0;

		for (int j = 0; j < i; j++) {
			Sum += Matrix[i][HalfSize - i + j] * Output[j];
		}
		Output[i] = (Vector[i] - Sum) / Diag[i];
	}

	for (int i = HalfSize; i < Matrix.size(); i++) {

		accVarType Sum = 0;
		for (int j = 0; j < HalfSize; j++) {
			Sum += Matrix[i][j] * Output[j + i - HalfSize];
		}
		Output[i] = (Vector[i] - Sum) / Diag[i];
	}

	return Output;
}

std::vector<real> SolverOfSLAE::SolveWithHigherTriangle(const std::vector<std::vector<real>>& Matrix,
	const std::vector<real>& Diag,
	const std::vector<real>& Vector)
{
	if (Matrix.empty())
		return {};

	std::vector<real> Output(Vector.size());
	const int HalfSize = Matrix[0].size();
	const int MatrixSize = Matrix.size();

	for (int i = MatrixSize; i >= MatrixSize - HalfSize; i--) {

		accVarType Sum = 0;
		for (int k = 0; k < MatrixSize - i; k++) {
			Sum += Matrix[i + k][HalfSize - k - 1] * Output[i + k];
		}
		Output[i - 1] = (Vector[i - 1] - Sum) / Diag[i - 1];
	}

	for (int i = MatrixSize - HalfSize; i > 0; i--) {

		accVarType Sum = 0;
		for (int k = 0; k < HalfSize; k++) {
			Sum += Matrix[i + k][HalfSize - 1 - k] * Output[i + k];
		}
		Output[i - 1] = (Vector[i - 1] - Sum) / Diag[i - 1];
	}

	return Output;
}