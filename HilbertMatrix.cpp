#include "HilbertMatrix.h"

std::vector<std::vector<real>> HilbertMatrix::GenerateALMatrix(const int Size)
{
	if (Size <= 0)
		throw "Attempt to generate invalid matrix";

	std::vector<std::vector<real>> Matrix(Size, std::vector<real>(Size));

	for (int i = 1; i < Size; i++)
	{
		for (int j = Size - i; j < Size; j++)
		{
			Matrix[i][j] = 1.0 / (2 * i + j - (Size - 2));
		}
	}
	return Matrix;
}

std::vector<real> HilbertMatrix::GenerateDiag(const int Size)
{
	if (Size <= 0)
		throw "Attempt to generate invalid vector";

	std::vector<real> Diag(Size);

	for (int i = 0; i < Size; i++)
	{
		Diag[i] = 1 / (2 * i + 1);
	}
	return Diag;
}