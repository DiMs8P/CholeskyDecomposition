#include "SolverOfSLAE.h"

vector<real> SolverOfSLAE::SolveWithLALowerTriangle(
	const vector<vector<real>>& Matrix,
	const vector<real>& Diag,
	const vector<real>& Vector)
{
	if (Matrix.empty())
		return {};

	vector<real> Output(Vector.size());
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

vector<real> SolverOfSLAE::SolveWithLAHigherTriangle(const vector<vector<real>>& Matrix,
	const vector<real>& Diag,
	const vector<real>& Vector)
{
	if (Matrix.empty())
		return {};

	vector<real> Output(Vector.size());
	const int HalfSize = Matrix[0].size();
	const int MatrixSize = Matrix.size();

	for (int i = MatrixSize; i >= MatrixSize - HalfSize && i > 0; i--) {

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


vector<real> SolverOfSLAE::SolveByGaussMethod(vector<vector<real>>& Matrix, const vector<real>& Vector)
{
	if (Matrix.size() != Vector.size() || Vector.empty())
		return{};

	ToUpperTriangle(Matrix);
	return SolveWithUpperTriangle(Matrix, Vector);
}

void SolverOfSLAE::ToUpperTriangle(vector<vector<real>>& Matrix)
{
	for (int i = 0; i < Matrix.size(); i++)
	{

		for (int j = i + 1; j < Matrix.size(); j++)
		{
			const real coefficient = -Matrix[j][i] / Matrix[i][i];

			AddRowWithCoefficient(Matrix[j], Matrix[i], coefficient);
		}
	}
}

void SolverOfSLAE::AddRowWithCoefficient(vector<real>& target, vector<real>& additional, const real coefficient)
{
	for (int j = 0; j < target.size(); j++)
	{
		target[j] += additional[j] * coefficient;
	}
}

vector<real> SolverOfSLAE::SolveWithUpperTriangle(vector<vector<real>>& Matrix, const vector<real>& Vector)
{
	vector<real> Output(Vector.size());

	for (int i = Matrix.size() - 1; i >= 0; i--)
	{
		accVarType sum = 0;
		for (int j = i + 1; j < Matrix.size(); ++j)
		{
			sum += Matrix[i][j] * Vector[j];
		}

		Output[i] = (Vector[i] - sum) / Matrix[i][i];
	}
	return Output;
}
