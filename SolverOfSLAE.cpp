#include "SolverOfSLAE.h"

std::vector<real> SolverOfSLAE::SolveWithLowerTriangle(
	const std::vector<std::vector<real>>& Matrix,
	const std::vector<real> Diag,
	const std::vector<real> Vector)
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
			Accumulator += Matrix[i][j] * Output[j];
		}
		Output[i] = (Vector[i] - Accumulator) / Diag[i];
		Accumulator = 0;
	}

	return Output;
}

std::vector<real> SolveWithHigherTriangle(const std::vector<std::vector<real>>& Matrix,
	const std::vector<real> Diag,
	const std::vector<real> Vector)
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
			Accumulator += Matrix[i][j] * Output[j];
		}
		Output[i] = (Vector[i] - Accumulator) / Diag[i];
		Accumulator = 0;
	}

	return Output;

}