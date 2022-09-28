#pragma once

#include "../Config.h"
#include <vector>

class Decompositor
{
public:
	void DecomposeByCholesky(vector<vector<real>>& Matrix, vector<real>& Vector);

private:
	void DecomposeTheFirstHalfWidth(vector<vector<real>>& Matrix, vector<real>& Vector);
	void FinishDecomposition(vector<vector<real>>& Matrix, vector<real>& Vector);
};

