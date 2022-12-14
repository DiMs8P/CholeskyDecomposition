#include "HilbertTapeMatrix.h"

HilbertTapeMatrix::HilbertTapeMatrix(
	const int dimension,
	const FileWriter& matrixWriter,
	const FileWriter& diagWriter
) :
	_matrixWriter(matrixWriter),
	_diagWriter(diagWriter)
{
	if (dimension <= 0)
		throw exception("Attempt to generate invalid matrix");

	_dimension = dimension;
	_matrix = vector<vector<real>>(0);
	FillMatrix();
	FillDiag();
}

void HilbertTapeMatrix::FillMatrix()
{
	_matrix = vector<vector<real>>(_dimension, vector<real>(_dimension));

	for (int i = 1; i < _dimension; i++)
		for (int j = _dimension - i; j < _dimension; j++)
			_matrix[i][j] = 1.0 / (2 * (sumType)i + j - (_dimension - 2));
}

void HilbertTapeMatrix::FillDiag()
{
	_diag = vector<real>(_dimension);

	for (int i = 0; i < _dimension; i++)
		_diag[i] = 1.0 / (2 * (sumType)i + 1);
}

void HilbertTapeMatrix::Write() const
{
	_matrixWriter.WriteMatrix(_matrix);
	_diagWriter.WriteVector(_diag);
}

vector<real> HilbertTapeMatrix::GetProductByZeroToSizeVector(const int size)
{
	vector<real> output(size);

	for (int i = 0; i < size; i++)
	{
		sumType sum = 0;
		for (int j = 1; j <= size; j++)
		{
			sum += (sumType)j / ((sumType)j + i);
		}
		output[i] = sum;
	}

	return output;
}