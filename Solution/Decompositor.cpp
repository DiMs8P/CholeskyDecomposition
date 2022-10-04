#include "Decompositor.h"

void Decompositor::DecomposeByCholesky(vector<vector<real>>& matrix, vector<real>& Diag) {

	if (matrix.empty())
		return;

	DecomposeTheFirstHalfWidth(matrix, Diag);
	FinishDecomposition(matrix, Diag);
}

void Decompositor::DecomposeTheFirstHalfWidth(vector<vector<real>>& matrix, vector<real>& Diag) {

	const int tapeHalfWidth = matrix[0].size();
	for (int i = 0; i < tapeHalfWidth; i++)
	{
		for (int jL = tapeHalfWidth - i; jL < tapeHalfWidth; jL++)
		{
			sumType sum = 0;
			const int j = jL - (tapeHalfWidth - i);
			for (int kj = 0, kjShift = i - j; kj < jL; kj++, kjShift++)
			{
				sum += matrix[i][kj] * matrix[j][kjShift];
			}
			matrix[i][jL] = (matrix[i][jL] - sum) / Diag[j];
		}

		sumType sum = 0;
		for (int jL = 0; jL < tapeHalfWidth; jL++)
		{
			sum += matrix[i][jL] * matrix[i][jL];
		}
		Diag[i] = sqrt(Diag[i] - sum);
	}
}

void Decompositor::FinishDecomposition(vector<vector<real>>& matrix, vector<real>& Diag) {

	const int tapeHalfWidth = matrix[0].size();
	const int matrixDimension = Diag.size();

	for (int i = tapeHalfWidth; i < matrixDimension; i++)
	{
		for (int jL = 0; jL < tapeHalfWidth; jL++)
		{
			sumType sum = 0;
			const int j = jL - (tapeHalfWidth - i);
			for (int kj = 0, kjShift = i - j; kj < jL; kj++, kjShift++)
			{
				sum += matrix[i][kj] * matrix[j][kjShift];
			}
			matrix[i][jL] = (matrix[i][jL] - sum) / Diag[j];
		}

		sumType sum = 0;
		for (int jL = 0; jL < tapeHalfWidth; jL++)
		{
			sum += matrix[i][jL] * matrix[i][jL];
		}
		Diag[i] = sqrt(Diag[i] - sum);
	}
}