#pragma once

#include "../Config.h"
#include <vector>

class SLAESolver
{
public:

	vector<real> SolveWithLALowerTriangle(const vector<vector<real>>& matrix,
		const vector<real>& diag,
		const vector<real>& Vector);

	vector<real> SolveWithLAHigherTriangle(const vector<vector<real>>& matrix,
		const vector<real>& diag,
		const vector<real>& Vector);

	vector<real> SolveByGaussMethod(vector<vector<real>>& matrix, const vector<real>& Vector);

private:
	vector<real> SolveWithUpperTriangle(vector<vector<real>>& matrix, const vector<real>& Vector);
	void ToUpperTriangle(vector<vector<real>>& matrix);
	void AddRowWithCoefficient(vector<real>& target, vector<real>& additional, const real coefficient);
};

