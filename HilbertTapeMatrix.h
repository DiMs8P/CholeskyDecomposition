#pragma once

#include <vector>
#include "Config.h"
#include "Input/Writer.h"
using namespace std;

class HilbertTapeMatrix
{
public:
	HilbertTapeMatrix(const int dimension, const FileWriter& matrixWriter, const FileWriter& diagWriter);
	void Write() const;
	static vector<real> GetProductByZeroToSizeVector(const int size);

private:
	void FillMatrix();
	void FillDiag();

	int _dimension;
	vector<vector<real>> _matrix;
	vector<real> _diag;
	const FileWriter& _matrixWriter;
	const FileWriter& _diagWriter;
};
