#include <vector>
#include "Decompositor.h"

void Decompositor::DecomposeByCholesky(std::vector<std::vector<real>>& Matrix, std::vector<real>& Diag) {

	if (Matrix.empty())
		return;

	DecomposeTheFirstHalfWidth(Matrix, Diag);
	FinishDecomposition(Matrix, Diag);
}

void Decompositor::DecomposeTheFirstHalfWidth(std::vector<std::vector<real>>& Matrix, std::vector<real>& Diag) {

	const int HalfWidth = Matrix[0].size();
	for (int i = 0; i < HalfWidth; i++)
	{
		for (int jL = HalfWidth - i; jL < HalfWidth; jL++)
		{
			accVarType Sum = 0;
			const int j = jL - (HalfWidth - i);
			for (int kj = 0, kjShift = i - j; kj < jL; kj++, kjShift++)
			{
				Sum += Matrix[i][kj] * Matrix[j][kjShift];
			}
			Matrix[i][jL] = (Matrix[i][jL] - Sum) / Diag[j];
		}

		accVarType Sum = 0;
		for (int jL = 0; jL < HalfWidth; jL++)
		{
			Sum += Matrix[i][jL] * Matrix[i][jL];
		}
		Diag[i] = sqrt(Diag[i] - Sum);
	}
}

void Decompositor::FinishDecomposition(std::vector<std::vector<real>>& Matrix, std::vector<real>& Diag) {

	const int HalfWidth = Matrix[0].size();
	const int MatrixSize = Diag.size();

	for (int i = HalfWidth; i < MatrixSize; i++)
	{
		for (int jL = 0; jL < HalfWidth; jL++)
		{
			accVarType Sum = 0;
			const int j = jL - (HalfWidth - i);
			for (int kj = 0, kjShift = i - j; kj < jL; kj++, kjShift++)
			{
				Sum += Matrix[i][kj] * Matrix[j][kjShift];
			}
			Matrix[i][jL] = (Matrix[i][jL] - Sum) / Diag[j];
		}

		accVarType Sum = 0;
		for (int jL = 0; jL < HalfWidth; jL++)
		{
			Sum += Matrix[i][jL] * Matrix[i][jL];
		}
		Diag[i] = sqrt(Diag[i] - Sum);
	}
}