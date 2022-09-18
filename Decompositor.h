#pragma once

#include <vector>
#include "Config.h"

class Decompositor
{
public:
	void DecomposeByCholesky(std::vector<std::vector<real>>& Matrix, std::vector<real>& Vector);

private:
	static void DecomposeTheFirstHalfWidth(std::vector<std::vector<real>>& Matrix, std::vector<real>& Vector);
	static void FinishDecomposition(std::vector<std::vector<real>>& Matrix, std::vector<real>& Vector);
};

