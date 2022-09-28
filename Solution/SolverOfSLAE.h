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

	std::vector<real> SolveByGaussMethod(std::vector<std::vector<real>>& Matrix, const std::vector<real>& Vector);

//private:
	std::vector<real> SolveWithUpperTriangle(std::vector<std::vector<real>>& Matrix, const std::vector<real>& Vector);
	void ToUpperTriangle(std::vector<std::vector<real>>& Matrix);
	void AddRowWithCoefficient(std::vector<real>& target, std::vector<real>& additional, const real coefficient);
};

