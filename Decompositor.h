#pragma once

#include "Config.h"

class vector;

class Decompositor
{
public:
	void DecomposeByCholesky(std::vector<std::vector<real>>& Matrix, std::vector<real>& Vector);

private:
	void DecomposeTheFirstHalfWidth(std::vector<std::vector<real>>& Matrix, std::vector<real>& Vector);
	void FinishDecomposition(std::vector<std::vector<real>>& Matrix, std::vector<real>& Vector);
};

