#pragma once

#include "../Config.h"
#include <vector>

class SolverOfSLAE
{
public:

	std::vector<real> SolveWithLALowerTriangle(const std::vector<std::vector<real>>& Matrix,
		const std::vector<real>& Diag,
		const std::vector<real>& Vector);

	std::vector<real> SolveWithLAHigherTriangle(const std::vector<std::vector<real>>& Matrix,
		const std::vector<real>& Diag,
		const std::vector<real>& Vector);

	std::vector<real> SolveByGaussMethod(const std::vector<std::vector<real>>& Matrix, const std::vector<real>& Vector);

};

