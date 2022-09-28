#pragma once

#include <vector>
#include "Config.h"
#include "Input/Writer.h"
using namespace std;

class ALHilbertMatrix
{
public:
	ALHilbertMatrix(const int size, const FileWriter& matrixWriter, const FileWriter& diagWriter);
	void Write() const;
private:
	void FillMatrix();
	void FillDiag();


	int _size;
	vector<vector<real>> _matrix;
	vector<real> _diag;
	const FileWriter& _matrixWriter;
	const FileWriter& _diagWriter;
};
