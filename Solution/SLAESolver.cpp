#include "SLAESolver.h"

vector<real> SLAESolver::SolveWithTapeMatrixAsLowerTriangle(
	const vector<vector<real>>& matrix,
	const vector<real>& diag,
	const vector<real>& Vector)
{
	if (matrix.empty())
		return {};

	vector<real> output(Vector.size());
	const int tapeHalfWidth = matrix[0].size();

	for (int i = 0; i < tapeHalfWidth; i++) {

		sumType sum = 0;

		for (int j = 0; j < i; j++) {
			sum += matrix[i][tapeHalfWidth - i + j] * output[j];
		}
		output[i] = (Vector[i] - sum) / diag[i];
	}

	for (int i = tapeHalfWidth; i < matrix.size(); i++) {

		sumType sum = 0;
		for (int j = 0; j < tapeHalfWidth; j++) {
			sum += matrix[i][j] * output[j + i - tapeHalfWidth];
		}
		output[i] = (Vector[i] - sum) / diag[i];
	}

	return output;
}

vector<real> SLAESolver::SolveWithTapeMatrixAsHigherTriangle(const vector<vector<real>>& matrix,
	const vector<real>& diag,
	const vector<real>& Vector)
{
	if (matrix.empty())
		return {};

	vector<real> output(Vector.size());
	const int tapeHalfWidth = matrix[0].size();
	const int matrixDimension = matrix.size();

	for (int i = matrixDimension; i >= matrixDimension - tapeHalfWidth && i > 0; i--) {

		sumType sum = 0;
		for (int k = 0; k < matrixDimension - i; k++) {
			sum += matrix[i + k][tapeHalfWidth - k - 1] * output[i + k];
		}
		output[i - 1] = (Vector[i - 1] - sum) / diag[i - 1];
	}

	for (int i = matrixDimension - tapeHalfWidth; i > 0; i--) {

		sumType sum = 0;
		for (int k = 0; k < tapeHalfWidth; k++) {
			sum += matrix[i + k][tapeHalfWidth - 1 - k] * output[i + k];
		}
		output[i - 1] = (Vector[i - 1] - sum) / diag[i - 1];
	}

	return output;
}

vector<real> SLAESolver::SolveByGaussMethod(vector<vector<real>>& matrix, const vector<real>& Vector)
{
	if (matrix.size() != Vector.size() || Vector.empty())
		return{};

	ToUpperTriangle(matrix);
	return SolveWithUpperTriangle(matrix, Vector);
}

void SLAESolver::ToUpperTriangle(vector<vector<real>>& matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = i + 1; j < matrix.size(); j++)
		{
			const real coefficient = -matrix[j][i] / matrix[i][i];

			AddRowWithCoefficient(matrix[j], matrix[i], coefficient);
		}
	}
}

void SLAESolver::AddRowWithCoefficient(vector<real>& target, vector<real>& additional, const real coefficient)
{
	for (int j = 0; j < target.size(); j++)
		target[j] += additional[j] * coefficient;
}

vector<real> SLAESolver::SolveWithUpperTriangle(vector<vector<real>>& matrix, const vector<real>& Vector)
{
	vector<real> output(Vector.size());

	for (int i = matrix.size() - 1; i >= 0; i--)
	{
		sumType sum = 0;
		for (int j = i + 1; j < matrix.size(); ++j)
		{
			sum += matrix[i][j] * Vector[j];
		}

		output[i] = (Vector[i] - sum) / matrix[i][i];
	}
	return output;
}
 