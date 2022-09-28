#include "HilbertMatrix.h"

ALHilbertMatrix::ALHilbertMatrix(
	const int size,
	const FileWriter& matrixWriter,
	const FileWriter& diagWriter
) :
	_matrixWriter(matrixWriter),
	_diagWriter(diagWriter)
{
	if (size <= 0)
		throw exception("Attempt to generate invalid matrix");
	_size = size;
	_matrix = vector<vector<real>>(0);
	FillMatrix();
	FillDiag();
}

void ALHilbertMatrix::FillMatrix()
{
	_matrix = vector<vector<real>>(_size, vector<real>(_size));

	for (int i = 1; i < _size; i++)
	{
		for (int j = _size - i; j < _size; j++)
		{
			_matrix[i][j] = 1.0 / (2 * i + j - (_size - 2));
		}
	}
}

void ALHilbertMatrix::FillDiag()
{
	_diag = vector<real>(_size);

	for (int i = 0; i < _size; i++)
	{
		_diag[i] = 1.0 / (2 * i + 1);
	}
}

void ALHilbertMatrix::Write() const
{
	_matrixWriter.WriteMatrix(_matrix);
	_diagWriter.WriteVector(_diag);
}

vector<real> ALHilbertMatrix::GetProductByVector(const int hilbertMatrixSize)
{
	std::vector<real> Output(hilbertMatrixSize);
	for (int i = 0; i < hilbertMatrixSize; i++)
	{
		accVarType Sum = 0;
		for (int j = 1; j <= hilbertMatrixSize; j++)
		{
			Sum += (accVarType)j / (j + i);
		}
		Output[i] = Sum;
	}
	return Output;
}