#pragma once

#include <vector>
#include "Config.h"

class Decompositor
{
public:
	void DecomposeByCholesky(std::vector<std::vector<real>>& Matrix, std::vector<real> Vector);

private:
	void DecomposeTheFirstHalfWidth(std::vector<std::vector<real>>& Matrix, std::vector<real> Vector, const int HalfWidth);
};

