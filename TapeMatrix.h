#pragma once

#include <vector>
#include "Config.h"

class TapeMatrix
{
public:
	TapeMatrix() = default;
	TapeMatrix(const std::string InputMatrix, const std::string InputDiag);
	void ReadLAMatrix(const std::string& Path);
	void ReadLADiagonal(const std::string& Path);

	std::vector<std::vector<real>> GetMatrix() const {
		return Matrix;
	}
	std::vector<real> GetDiagonal() const {
		return Diag;
	}

private:
	std::vector<std::vector<real>> Matrix;
	std::vector<real> Diag;
};

