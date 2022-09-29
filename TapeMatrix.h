#pragma once

#include <string>
#include <vector>
#include "Config.h"

class TapeMatrix
{
public:
	TapeMatrix() = default;
	TapeMatrix(const string inputMatrix, const string inputDiag);
	void ReadLAMatrix(const string& path);
	void ReadLADiagonal(const string& path);

	vector<vector<real>> GetMatrix() const {
		return _matrix;
	}
	vector<real> GetDiagonal() const {
		return _diag;
	}

private:
	vector<vector<real>> _matrix;
	vector<real> _diag;
};

