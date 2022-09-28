#include "HilbertMatrix.h"

vector<vector<real>> HilbertMatrix::GenerateALMatrix(const int Size)
{
	if (Size <= 0)
		throw "Attempt to generate invalid matrix";

	vector<vector<real>> Matrix(Size, vector<real>(Size));

	for (int i = 1; i < Size; i++)
	{
		for (int j = Size - i; j < Size; j++)
		{
			Matrix[i][j] = 1.0f / (2 * i + j - (Size - 1));
		}
	}
	return Matrix;
}

vector<real> HilbertMatrix::GenerateDiag(const int Size)
{
	if (Size <= 0)
		throw "Attempt to generate invalid vector";

	vector<real> Diag(Size);

	for (int i = 0; i < Size; i++)
	{
		Diag[i] = 1.0f / (2 * i + 1);
	}
	return Diag;
}
