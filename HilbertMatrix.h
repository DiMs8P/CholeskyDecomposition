#pragma once

#include <vector>
#include "Config.h"

class HilbertMatrix
{
public:
	vector<vector<real>> GenerateALMatrix(const int Size);
	vector<real> GenerateDiag(const int Size);

	vector<real> GetHilbertMatrixXVectorProduct(const int HilbertMatrixSize)
	{
		vector<real> Output(HilbertMatrixSize);
		for (int i = 0; i < HilbertMatrixSize; i++)
		{
			accVarType Sum = 0;
			for (int j = 1; j <= HilbertMatrixSize; j++)
			{
				Sum += (accVarType)j / (j + i);
			}
			Output[i] = Sum;
		}
		return Output;
	}

};
