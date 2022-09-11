#pragma once

#include <vector>
#include "Config.h"

class SolverOfSLAE
{
public:

	std::vector<real> SolveWithLowerTriangle(const std::vector<std::vector<real>>& Matrix,
		const std::vector<real> Diag,
		const std::vector<real> Vector);

	std::vector<real> SolveWithHigherTriangle(const std::vector<std::vector<real>>& Matrix,
		const std::vector<real> Diag,
		const std::vector<real> Vector);
};

