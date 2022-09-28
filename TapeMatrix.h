#pragma once

#include <vector>
#include "Config.h"

class TapeMatrix
{
public:
	TapeMatrix() = default;
	TapeMatrix(const string InputMatrix, const string InputDiag);
	void ReadLAMatrix(const string& Path);
	void ReadLADiagonal(const string& Path);

	vector<vector<real>> GetMatrix() const {
		return Matrix;
	}
	vector<real> GetDiagonal() const {
		return Diag;
	}

private:
	vector<vector<real>> Matrix;
	vector<real> Diag;
};

