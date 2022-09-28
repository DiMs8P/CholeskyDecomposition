#pragma once

#include "../Config.h"
#include <vector>

class SolverOfSLAE
{
public:

	vector<real> SolveWithLALowerTriangle(const vector<vector<real>>& Matrix,
		const vector<real>& Diag,
		const vector<real>& Vector);

	vector<real> SolveWithLAHigherTriangle(const vector<vector<real>>& Matrix,
		const vector<real>& Diag,
		const vector<real>& Vector);

	vector<real> SolveByGaussMethod(vector<vector<real>>& Matrix, const vector<real>& Vector);

//private:
	vector<real> SolveWithUpperTriangle(vector<vector<real>>& Matrix, const vector<real>& Vector);
	void ToUpperTriangle(vector<vector<real>>& Matrix);
	void AddRowWithCoefficient(vector<real>& target, vector<real>& additional, const real coefficient);
};

